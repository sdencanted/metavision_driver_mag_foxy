// -*-c++-*---------------------------------------------------------------------------------------
// Copyright 2022 Bernd Pfrommer <bernd.pfrommer@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef METAVISION_ROS_DRIVER__SYNC_TEST_ROS1_H_
#define METAVISION_ROS_DRIVER__SYNC_TEST_ROS1_H_

#include <event_array_msgs/EventArray.h>
#include <ros/ros.h>

#include <memory>
#include <string>

namespace metavision_ros_driver
{
class SyncTestROS1
{
public:
  explicit SyncTestROS1(const ros::NodeHandle & nh);
  ~SyncTestROS1();

private:
  using EventArray = event_array_msgs::EventArray;
  using EventArrayConstPtr = EventArray::ConstPtr;

  bool start();
  void resetVariables();
  void callbackCam0(EventArrayConstPtr events);
  void callbackCam1(EventArrayConstPtr events);

  // ---------  variables
  ros::NodeHandle nh_;
  ros::Subscriber camSub_[2];
  uint64_t statInterval_{1000000000LL};
  uint64_t lastTimeCam0_{0};
  uint64_t lastTimeStats_{0};
  double sumOfDiffs_{0};
  double sumOfDiffWall_{0};
  uint64_t count_{0};
  int64_t maxDiff_;
  int64_t minDiff_;
  bool useROSTime_{false};
};
}  // namespace metavision_ros_driver
#endif  // METAVISION_ROS_DRIVER__SYNC_TEST_ROS1_H_
