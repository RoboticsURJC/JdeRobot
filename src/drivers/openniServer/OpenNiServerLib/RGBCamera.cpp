//
// Created by frivas on 24/01/17.
//

#include <jderobot/logger/Logger.h>
#include "RGBCamera.h"


namespace openniServer{
    RGBCamera::RGBCamera(std::string propertyPrefix, Ice::CommunicatorPtr ic,ConcurrentDevicePtr device) : CameraHandler(propertyPrefix, ic),device(device) {

        framerateN = prop->getPropertyAsIntWithDefault(prefix+"fps",25);

        std::string fmtStr = prop->getPropertyWithDefault(prefix+"Format","YUY2");//default format YUY2
        imageFmt = colorspaces::Image::Format::searchFormat(fmtStr);
        if (!imageFmt)
            jderobot::Logger::getInstance()->warning( "Format " + fmtStr + " unknown" );
        imageDescription->size = imageDescription->width * imageDescription->height * CV_ELEM_SIZE(imageFmt->cvType);
        imageDescription->format = imageFmt->name;

        jderobot::Logger::getInstance()->info( "Starting thread for camera: " + cameraDescription->name );
        replyTask = new ReplyTask(this, framerateN, device);

        this->control=replyTask->start();//my own thread

    }

    void RGBCamera::getImageData_async(const jderobot::AMD_ImageProvider_getImageDataPtr &cb, const std::string &format,
                                       const Ice::Current &c) {
        replyTask->pushJob(cb, format);

    }

    RGBCamera::ReplyTask::ReplyTask(const jderobot::Camera *camera, int fps,ConcurrentDevicePtr device) : CameraTask(camera, fps),device(device) {

    }

    void RGBCamera::ReplyTask::createCustomImage(cv::Mat &image) {
        image=this->device->getRGBImage();
    }

}