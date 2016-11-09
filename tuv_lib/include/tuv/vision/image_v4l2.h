/*
 * This file is part of the XXX distribution (https://github.com/xxxx or http://xxx.github.io).
 * Copyright (c) 2016 Freek van Tienen <freek.v.tienen@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef VISION_IMAGE_V4L2_H_
#define VISION_IMAGE_V4L2_H_

#include <tuv/vision/image.h>
#include <tuv/cam/cam_linux.h>

/**
 * @brief Image based on a V4L2 buffer
 *
 * This is an image based on a V4L2 memory mapped buffer. These images should only be created
 * by the Linux Camera. At deconstruction it will automatically enqueue the V4L2 buffer.
 */
class ImageV4L2: public Image {
  private:
    CamLinux *cam;          ///< Pointer to the Linux camera who took the image
    uint16_t buffer_index;  ///< Index of the buffer in the linux camera

  public:
    ImageV4L2(CamLinux *cam, uint16_t buffer_index, void *data);
    ~ImageV4L2(void);
};

#endif /* VISION_IMAGE_V4L2_H_ */
