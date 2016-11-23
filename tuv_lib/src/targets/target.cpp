/*
 * This file is part of the TUV library (https://github.com/tudelft/tudelft_vision).
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

#include "targets/target.h"

/**
 * @brief Get a specific camera
 *
 * This will search in the list with cameras for the camera with the specified ID.
 * @param id The camera ID to request
 * @return Pointer to the camera (will be nullptr if not found)
 */
Cam::Ptr Target::getCamera(uint32_t id) {
    /* Search in the list of cameras */
    for(auto pair : cams) {
        if(pair.first == id)
            return pair.second;
    }

    return nullptr;
}
