/*
* Copyright (c) 2018-present, aliminabc@gmail.com.
*
* This source code is licensed under the MIT license found in the
* LICENSE file in the root directory of this source tree.
*/

#ifndef HWVC_ANDROID_ALCONTEXT_H
#define HWVC_ANDROID_ALCONTEXT_H

#include "AlAbsContext.h"

al_class_ex(AlContext, AlAbsContext) {
public:
    AlContext();

    ~AlContext();
};


#endif //HWVC_ANDROID_ALCONTEXT_H