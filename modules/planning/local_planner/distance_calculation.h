/****************************************************************************
 *  Copyright (C) 2018 RoboMaster.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of 
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2016,
 *  TU Dortmund - Institute of Control Theory and Systems Engineering.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the institute nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 * Author: Christoph Rösmann
 *********************************************************************/

#ifndef MODULES_PLANNING_LOCAL_PLANNER_DISTANCE_CALCULATIONS_H
#define MODULES_PLANNING_LOCAL_PLANNER_DISTANCE_CALCULATIONS_H

#include <Eigen/Core>
#include "modules/planning/local_planner/utility_tool.h"


namespace rrts {
namespace planning {
namespace local_planner {

typedef std::vector<Eigen::Vector2d, Eigen::aligned_allocator<Eigen::Vector2d> > Point2dContainer;

inline Eigen::Vector2d ClosestPointOnLineSegment2D(const Eigen::Ref<const Eigen::Vector2d> &point,
                                                        const Eigen::Ref<const Eigen::Vector2d> &line_start,
                                                        const Eigen::Ref<const Eigen::Vector2d> &line_end) {
  Eigen::Vector2d diff = line_end - line_start;
  double sq_norm = diff.squaredNorm();

  if (sq_norm == 0){
    return line_start;
  }

  double u = ((point.x() - line_start.x()) * diff.x() + (point.y() - line_start.y()) * diff.y()) / sq_norm;

  if (u <= 0) {
    return line_start;
  } else if (u >= 1) {
    return line_end;
  }

  return line_start + u * diff;
}

inline double DistancePointToSegment2D(const Eigen::Ref<const Eigen::Vector2d> &point,
                                           const Eigen::Ref<const Eigen::Vector2d> &line_start,
                                           const Eigen::Ref<const Eigen::Vector2d> &line_end) {
  return (point - ClosestPointOnLineSegment2D(point, line_start, line_end)).norm();
}

inline bool CheckLineSegmentsIntersection2D(const Eigen::Ref<const Eigen::Vector2d> &line1_start,
                                                const Eigen::Ref<const Eigen::Vector2d> &line1_end,
                                                const Eigen::Ref<const Eigen::Vector2d> &line2_start,
                                                const Eigen::Ref<const Eigen::Vector2d> &line2_end,
                                                Eigen::Vector2d *intersection = NULL) {
  double s_numer, t_numer, denom, t;
  Eigen::Vector2d line1 = line1_end - line1_start;
  Eigen::Vector2d line2 = line2_end - line2_start;

  denom = line1.x() * line2.y() - line2.x() * line1.y();
  if (denom == 0) return false;
  bool denomPositive = denom > 0;

  Eigen::Vector2d aux = line1_start - line2_start;

  s_numer = line1.x() * aux.y() - line1.y() * aux.x();
  if ((s_numer < 0) == denomPositive) return false;

  t_numer = line2.x() * aux.y() - line2.y() * aux.x();
  if ((t_numer < 0) == denomPositive) return false;

  if (((s_numer > denom) == denomPositive) || ((t_numer > denom) == denomPositive)) return false;

  t = t_numer / denom;
  if (intersection) {
    *intersection = line1_start + t * line1;
  }

  return true;
}

inline double DistanceSegmentToSegment2D(const Eigen::Ref<const Eigen::Vector2d> &line1_start,
                                             const Eigen::Ref<const Eigen::Vector2d> &line1_end,
                                             const Eigen::Ref<const Eigen::Vector2d> &line2_start,
                                             const Eigen::Ref<const Eigen::Vector2d> &line2_end) {

  if (CheckLineSegmentsIntersection2D(line1_start, line1_end, line2_start, line2_end)){
    return 0;
  }

  std::array<double, 4> distances;

  distances[0] = DistancePointToSegment2D(line1_start, line2_start, line2_end);
  distances[1] = DistancePointToSegment2D(line1_end, line2_start, line2_end);
  distances[2] = DistancePointToSegment2D(line2_start, line1_start, line1_end);
  distances[3] = DistancePointToSegment2D(line2_end, line1_start, line1_end);

  return *std::min_element(distances.begin(), distances.end());
}

inline double DistancePointToPolygon2D(const Eigen::Vector2d &point, const Point2dContainer &vertices) {
  double dist = HUGE_VAL;

  if (vertices.size() == 1) {
    return (point - vertices.front()).norm();
  }

  for (int i = 0; i < (int) vertices.size() - 1; ++i) {
    double new_dist = DistancePointToSegment2D(point, vertices.at(i), vertices.at(i + 1));
    if (new_dist < dist) {
      dist = new_dist;
    }
  }

  if (vertices.size() > 2) {
    double new_dist = DistancePointToSegment2D(point, vertices.back(), vertices.front());
    if (new_dist < dist) {
      return new_dist;
    }
  }

  return dist;
}

inline double DistanceSegmentToPolygon2D(const Eigen::Vector2d &line_start,
                                             const Eigen::Vector2d &line_end,
                                             const Point2dContainer &vertices) {
  double dist = HUGE_VAL;

  if (vertices.size() == 1) {
    return DistancePointToSegment2D(vertices.front(), line_start, line_end);
  }

  for (int i = 0; i < (int) vertices.size() - 1; ++i) {
    double new_dist = DistanceSegmentToSegment2D(line_start, line_end, vertices.at(i), vertices.at(i + 1));
    if (new_dist < dist) {
      dist = new_dist;
    }
  }

  if (vertices.size() > 2) {
    double new_dist =
        DistanceSegmentToSegment2D(line_start, line_end, vertices.back(), vertices.front());
    if (new_dist < dist)
      return new_dist;
  }

  return dist;
}

inline double DistancePolygonToPolygon2D(const Point2dContainer &vertices1, const Point2dContainer &vertices2) {
  double dist = HUGE_VAL;

  if (vertices1.size() == 1) {
    return DistancePointToPolygon2D(vertices1.front(), vertices2);
  }

  for (int i = 0; i < (int) vertices1.size() - 1; ++i) {
    double new_dist = DistanceSegmentToPolygon2D(vertices1[i], vertices1[i + 1], vertices2);
    if (new_dist < dist) {
      dist = new_dist;
    }
  }

  if (vertices1.size() > 2) {
    double new_dist = DistanceSegmentToPolygon2D(vertices1.back(), vertices1.front(), vertices2);
    if (new_dist < dist) {
      return new_dist;
    }
  }

  return dist;
}


} // namespace local_planner
} // namespace planning
} // namespace rrts
#endif // MODULES_PLANNING_LOCAL_PLANNER_DISTANCE_CALCULATIONS_H
