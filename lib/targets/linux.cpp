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

#include "linux.h"

#include <iostream>
#include "cam/cam_linux.h"
#include "drivers/clogger.h"

Linux::Linux(void) {
    CLogger::addAllOutput(&std::cout);
}

Cam::Ptr Linux::getCamera(uint32_t id) {
    /* First try to find if the camera already exists */
    Cam::Ptr cam = Target::getCamera(id);

    /* Create the camera if needed */
    if(cam == nullptr) {
        cam = std::make_shared<CamLinux>("/dev/video" + std::to_string(id));
    }

    return cam;
}
