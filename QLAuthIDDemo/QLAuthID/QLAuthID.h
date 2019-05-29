//
//  QLAuthID.h
//  QLAuthIDDemo
//
//  Created by qiu on 2019/5/29.
//  Copyright © 2019 qiu. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 TouchID/FaceID 状态
 */
typedef NS_ENUM(NSUInteger, QLAuthIDState){
    
    /*!
     *  当前设备不支持TouchID/FaceID
     */
    QLAuthIDStateNotSupport = 0,
    /*!
     TouchID/FaceID 验证成功
     */
    QLAuthIDStateSuccess = 1,
    /*!
     TouchID/FaceID 验证失败
     */
    QLAuthIDStateFail = 2,
    /*!
     TouchID/FaceID 被用户手动取消
     */
    QLAuthIDStateUserCancel = 3,
    /*!
     用户不使用TouchID/FaceID,选择手动输入密码
     */
    QLAuthIDStateInputPassword = 4,
    /*!
     TouchID/FaceID 被系统取消 (如遇到来电,锁屏,按了Home键等)
     */
    QLAuthIDStateSystemCancel = 5,
    /*!
     TouchID/FaceID 无法启动,因为用户没有设置密码
     */
    QLAuthIDStatePasswordNotSet = 6,
    /*!
     TouchID/FaceID 无法启动,因为用户没有设置TouchID/FaceID
     */
    QLAuthIDStateTouchIDNotSet = 7,
    /*!
     *  TouchID/FaceID 无效
     */
    QLAuthIDStateTouchIDNotAvailable = 8,
    /*!
     TouchID/FaceID 被锁定(连续多次验证TouchID/FaceID失败,系统需要用户手动输入密码)
     */
    QLAuthIDStateTouchIDLockout = 9,
    /*!
     当前软件被挂起并取消了授权 (如App进入了后台等)
     */
    QLAuthIDStateAppCancel = 10,
    /*!
     当前软件被挂起并取消了授权 (LAContext对象无效)
     */
    QLAuthIDStateInvalidContext = 11,
    /*!
     系统版本不支持TouchID/FaceID (必须高于iOS 8.0才能使用)
     */
    QLAuthIDStateVersionNotSupport = 12
};

typedef NS_ENUM(NSUInteger, QLAuthSupportID){
    QLAuthNotSupport = 0, //暂不支持
    QLAuthSupportTouchID, //touchID
    QLAuthSupportFaceID   //faceID
    
};

typedef void (^QLAuthIDStateBlock)(QLAuthIDState state, NSError *error);

/*!
 实现是否支持TouchID/FaceID验证
 实现直接调用
 */
@interface QLAuthID : NSObject
+ (instancetype)sharedInstance;
/*!
 启动TouchID/FaceID进行验证
 @param describe TouchID/FaceID显示的描述
 @param block 回调状态的block
 */
- (void)ql_showAuthIDWithDescribe:(NSString *)describe block:(QLAuthIDStateBlock)block;

/*!
 验证是否支持TouchID/FaceID
 */
- (QLAuthSupportID)ql_authPhoneWithSupportID;


@end

