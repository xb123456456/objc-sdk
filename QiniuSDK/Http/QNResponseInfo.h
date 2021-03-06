//
//  QNResponseInfo.h
//  QiniuSDK
//
//  Created by bailong on 14/10/2.
//  Copyright (c) 2014年 Qiniu. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *    中途取消的状态码
 */
extern const int kQNRequestCancelled;

/**
 *    网络错误状态码
 */
extern const int kQNNetworkError;

/**
 *    错误参数状态码
 */
extern const int kQNInvalidArgument;

/**
 *    读取文件错误状态码
 */
extern const int kQNFileError;

/**
 *    上传完成后返回的状态信息
 */
@interface QNResponseInfo : NSObject

/**
 *    状态码
 */
@property (readonly) int statusCode;

/**
 *    七牛服务器生成的请求ID，用来跟踪请求信息，如果使用过程中出现问题，请反馈此ID
 */
@property (nonatomic, copy, readonly) NSString *reqId;

/**
 *    七牛服务器内部跟踪记录
 */
@property (nonatomic, copy, readonly) NSString *xlog;

/**
 *    错误信息，出错时请反馈此记录
 */
@property (nonatomic, copy, readonly) NSError *error;

/**
 *    是否取消
 */
@property (nonatomic, readonly, getter = isCancelled) BOOL canceled;

/**
 *    成功的请求
 */
@property (nonatomic, readonly, getter = isOK) BOOL ok;

/**
 *    是否网络错误
 */
@property (nonatomic, readonly, getter = isConnectionBroken) BOOL broken;

/**
 *    是否需要重试，内部使用
 */
@property (nonatomic, readonly) BOOL couldRetry;

/**
 *    工厂函数，内部使用
 *
 *    @return 取消的实例
 */
+ (instancetype)cancel;

/**
 *    工厂函数，内部使用
 *
 *    @param desc 错误参数描述
 *
 *    @return 错误参数实例
 */
+ (instancetype)responseInfoWithInvalidArgument:(NSString *)desc;

/**
 *    工厂函数，内部使用
 *
 *    @param error 错误信息
 *
 *    @return 网络错误实例
 */
+ (instancetype)responseInfoWithNetError:(NSError *)error;

/**
 *    工厂函数，内部使用
 *
 *    @param error 错误信息
 *
 *    @return 文件错误实例
 */
+ (instancetype)responseInfoWithFileError:(NSError *)error;

/**
 *    构造函数
 *
 *    @param status 状态码
 *    @param reqId  七牛服务器请求id
 *    @param xlog   七牛服务器记录
 *    @param body   服务器返回内容
 *
 *    @return 实例
 */
- (instancetype)init:(int)status
           withReqId:(NSString *)reqId
            withXLog:(NSString *)xlog
            withBody:(NSData *)body;

@end
