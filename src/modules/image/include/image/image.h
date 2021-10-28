﻿/**
 * @file image.h
 * @author mango (2321544362@qq.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MVK_IMAGE_H_
#define MVK_IMAGE_H_

#include "image/image_defines.h"
#include <string>
#include <memory>

namespace mvk
{
    class ImageImpl;                                                    ///< Image实现类声明

    /**
     * @brief 图像数据模块
     * 
     */
    class MVK_IMAGE_EXPORT Image
    {
    private:
        std::shared_ptr<ImageImpl> image_impl_;                         ///< image类实现对象
    public:
        Image() = delete;

        /**
         * @brief 构造函数
         * 
         * @param data(in) 图像数据
         * @param width(in) 图像宽度
         * @param height(in) 图像长度
         * @param format(in) 图像格式类型 
         */
        Image(const unsigned char* data, const size_t& width, const size_t& height, const IMAGE_FORMAT& format);
        
        ~Image();

        /**
         * @brief 读取图像文件
         * 
         * @param filename(in) 图像文件名名称 
         * @param format(in) 图像格式类型 
         * @return int 执行错误码，0为正常值
         */
        int Read(const std::string& filename,  const IMAGE_FORMAT& format);

        /**
         * @brief 保存图像至本地文件
         * 
         * @param filename(in) 文件名称
         * @return int 执行错误码，0为正常值
         */
        int Save(const std::string& filename);

        /**
         * @brief 获取图像数据
         * 
         * @return char* 数据指针首地址
         */
        unsigned char* GetData() const;

        /**
         * @brief 获取图像宽度
         * 
         * @return size_t 
         */
        size_t GetWidth() const;

        /**
         * @brief 获取图像高度
         * 
         * @return size_t 
         */
        size_t GetHeight() const;

        /**
         * @brief 获取图像通道数
         * 
         * @return size_t 
         */
        size_t GetChannel() const;

        /**
         * @brief 释放图像内存
         * 
         * @return int 执行错误码，0为正常值
         */
        int Release();
    };
    

} // namespace mvk

#endif //MVK_IMAGE_H_