/*
 * Copyright (c) 2018-present, lmyooyo@gmail.com.
 *
 * This source code is licensed under the GPL license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef HARDWAREVIDEOCODEC_HWBITMAP_H
#define HARDWAREVIDEOCODEC_HWBITMAP_H

#include "Object.h"
#include "AlColorSpace.h"
#include "AlBitmapInfo.h"
#include "HwResult.h"

al_class(AlBitmap) {
public:
    static AlBitmap *create(AlBitmapInfo info);

    static AlBitmap *create(int width, int height, AlColorSpace format);

    static float getImageFormatBytes(AlColorSpace format);

private:
    AlBitmap(AlBitmapInfo &info);

    AlBitmap(int width, int height, uint32_t depth, AlColorSpace format);

    AlBitmap(const AlBitmap &e) : Object() {};

public:
    virtual ~AlBitmap();

    int getWidth();

    int getHeight();

    /**
     * 改变HwBitmap大小和格式，用于内存复用
     */
    HwResult resize(int width, int height, AlColorSpace format);

    /**
     * 获取指向图片像素内存的指针
     */
    uint8_t *getPixels();

    /**
     * 获取图片占用的内存大小
     */
    uint64_t getByteSize();

    AlRational getRotation();

    void dump();

private:

    void config();

private:
    uint8_t *pixels = nullptr;//用于存储图片像素的buffer
    uint64_t byteSize = 0;
    AlBitmapInfo info;
};


#endif //HARDWAREVIDEOCODEC_HWBITMAP_H