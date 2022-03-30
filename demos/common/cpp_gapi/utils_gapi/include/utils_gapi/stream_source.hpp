// Copyright (C) 2021-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <memory>  // for shared_ptr

#include <opencv2/core.hpp>  // for Mat
#include <opencv2/gapi/gmetaarg.hpp>  // for GMetaArg
#include <opencv2/gapi/streaming/source.hpp>  // for IStreamSource

class ImagesCapture;
namespace cv {
namespace gapi {
namespace wip {
struct Data;
}  // namespace wip
}  // namespace gapi
}  // namespace cv

namespace custom {
class CommonCapSrc : public cv::gapi::wip::IStreamSource {
public:
    explicit CommonCapSrc(std::shared_ptr<ImagesCapture>& cap);

protected:
    std::shared_ptr<ImagesCapture> cap;
    cv::Mat first;
    bool first_pulled = false;

    void preparation();
    bool pull(cv::gapi::wip::Data& data) override;
    cv::GMetaArg descr_of() const override;
};

}  // namespace custom
