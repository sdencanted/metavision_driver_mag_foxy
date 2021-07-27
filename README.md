# metavision_ros_driver

A ROS driver for cameras using the metavison toolkit (Prophesee and
SilkyEVCam). This driver is not written or supported by Prophessee.
You can find their official ROS driver
[here](https://github.com/prophesee-ai/prophesee_ros_wrapper)


## Supported platforms

Currently only tested under ROS Noetic on Ubuntu 20.04.

## How to build
Create a workspace (``metavision_ros_driver_ws``), clone this repo, and use ``wstool``
to pull in the remaining dependencies:

```
mkdir -p ~/metavision_ros_driver_ws/src
cd ~/metavision_ros_driver_ws
git clone https://github.com/berndpfrommer/metavision_ros_driver src/metavision_ros_driver
wstool init src src/metavision_ros_driver/metavision_ros_driver.rosinstall
# to update an existing space:
# wstool merge -t src src/metavision_ros_driver/metavision_ros_driver.rosinstall
# wstool update -t src
```

Now configure and build:

```
catkin config -DCMAKE_BUILD_TYPE=RelWithDebInfo  # (optionally add -DCMAKE_EXPORT_COMPILE_COMMANDS=1)
catkin build
```

## Driver

Replacement driver for the Prophesee driver with the following improvements/changes:

- will write ``dvs_msgs`` instead of ``prophesee_msgs``. This permits
  using ROS based pipelines that have been developed for the DVS
  camera.
- less CPU consumption by avoiding unnecessary copies.
- implemented as nodelet so can be run in the same address space as
  e.g. a rosbag record nodelet without worrying of message loss in transmission.
- prints out message rate statistics.

How to run:

```
roslaunch metavision_ros_driver driver_node.launch
```

Parameters:

- ``bias_file``: path to file with camera biases. See example in the
  ``biases`` directory.
- ``message_time_threshold``: approximate time span [sec] of events to be
  aggregated before ROS message is sent.
- ``statistics_print_interval`` time in seconds between statistics printouts.

## License

This software is issued under the Apache License Version 2.0.