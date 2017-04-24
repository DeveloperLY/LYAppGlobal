//
//  LYMacros.h
///  LYAppGlobal
//
//  Created by Liu Y on 16/5/12.
//  Copyright © 2016年 DeveloperLY. All rights reserved.
//

#ifndef LYMacros_h
#define LYMacros_h

// MainScreen Height&Width
#define WIDTH_SCREEN                                [UIScreen mainScreen].bounds.size.width
#define HEIGHT_SCREEN                               [UIScreen mainScreen].bounds.size.height

// 中文字体
#ifdef isIOS9
#define CHINESE_FONT_NAME                           @"PingFang SC"
#else
#define CHINESE_FONT_NAME                           @"Helvetica"
#endif

#define CHINESE_SYSTEM(x)                           [UIFont fontWithName:CHINESE_FONT_NAME size:x]

// 不同屏幕尺寸字体适配（375，667是因为效果图为IPHONE6 如果不是则根据实际情况修改）
#define kScreenWidthRatio                           (WIDTH_SCREEN / 375.0)
#define kScreenHeightRatio                          (HEIGHT_SCREEN / 667.0)
#define AdaptedWidth(x)                             ceilf((x) * kScreenWidthRatio)
#define AdaptedHeight(x)                            ceilf((x) * kScreenHeightRatio)
#define kFontSize(R)                                CHINESE_SYSTEM(AdaptedWidth(R))

// 比例
#define Ratio320(args)                              args/320.0*HEIGHT_SCREEN
#define Ratio568(args)                              args/568.0*HEIGHT_SCREEN
#define Ratio640(args)                              args/640.0*HEIGHT_SCREEN
#define Ratio1136(args)                             args/1136.0*HEIGHT_SCREEN
#define Ratio375(args)                              args/375.0*WIDTH_SCREEN
#define Ratio667(args)                              args/667.0*HEIGHT_SCREEN

#define kScreenHeight                               MAX(WIDTH_SCREEN, HEIGHT_SCREEN)
#define kIPhone4s                                   (kScreenHeight == 480)
#define kIPhone5                                    (kScreenHeight == 568)
#define kIPhone6                                    (kScreenHeight == 667)
#define kIPhone6Plus                                (kScreenHeight == 736)

// 字体大小(常规/粗体)
#define BOLDSYSTEMFONT(FONTSIZE)                    [UIFont boldSystemFontOfSize:FONTSIZE]
#define SYSTEMFONT(FONTSIZE)                        [UIFont systemFontOfSize:FONTSIZE]
#define FONT(NAME, FONTSIZE)                        [UIFont fontWithName:(NAME) size:(FONTSIZE)]

// 优雅安全的执行Block
#define LY_SAFE_BLOCK(BlockName, ...)               ({ !BlockName ? nil : BlockName(__VA_ARGS__); })

//弱引用/强引用  可配对引用在外面用WeakSelf(self)，block用StrongSelf(self)  也可以单独引用在外面用WeakSelf(self) block里面用weakself
//#define WeakSelf(type)                            __weak __typeof(type) weak##type = type;
//#define StrongSelf(type)                          __strong __typeof(type) type = weak##type;

#define WeakSelf                                    __weak __typeof(&*self)weakSelf = self;
#define StrongSelf                                  __strong __typeof(&*self)strongSelf = self;


#ifdef DEBUG
#define NSLog(...)                                  NSLog(__VA_ARGS__) // 如果不需要打印数据，把这__  NSLog(__VA_ARGS__) ___注释了
#else
#define NSLog(...)
#endif

// Color
#define HexRGB(rgbValue)                            [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define HexRGBAlpha(rgbValue,alp)                   [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:alp]

#define LYColor(r, g, b)                            [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1.0]
#define LYColorAlpha(r, g, b, a)                    [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:a]

// 随机色
#define LYRandomColor                               LYColor(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256))


// 默认背景色
#define DEFAULT_BACKGROUND_COLOR                    LYColor(227.0, 232.0, 236.0)

// 是否大于等于iOS8
#define isIOS8                                      ([NSProcessInfo.processInfo isOperatingSystemAtLeastVersion:(NSOperatingSystemVersion){8,0,0}])
// 是否大于等于iOS9
#define isIOS9                                      ([NSProcessInfo.processInfo isOperatingSystemAtLeastVersion:(NSOperatingSystemVersion){9,0,0}])
// 是否大于等于iOS10
#define isIOS10                                     ([NSProcessInfo.processInfo isOperatingSystemAtLeastVersion:(NSOperatingSystemVersion){10,0,0}])

// 是否iPad
#define isPad                                       (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

// 字符串是否为空
#define kStringIsEmpty(str)                         ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )
// 数组是否为空
#define kArrayIsEmpty(array)                        (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)
// 字典是否为空
#define kDictIsEmpty(dic)                           (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0)
// 是否空对象
#define kObjectIsEmpty(_object)                     (_object == nil \
                                                    || [_object isKindOfClass:[NSNull class]] \
                                                    || ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
                                                    || ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))

//AppDelegate对象
#define AppDelegateInstance                         [[UIApplication sharedApplication] delegate]

// 一些缩写
#define kApplication                                [UIApplication sharedApplication]
#define kKeyWindow                                  [UIApplication sharedApplication].keyWindow
#define kUserDefaults                               [NSUserDefaults standardUserDefaults]
#define kNotificationCenter                         [NSNotificationCenter defaultCenter]

//获取当前语言
#define kCurrentLanguage                            ([[NSLocale preferredLanguages] objectAtIndex:0])


// 由角度转换弧度
#define kDegreesToRadian(x)                         (M_PI * (x) / 180.0)
//由弧度转换角度
#define kRadianToDegrees(radian)                    (radian * 180.0) / (M_PI)

// 在Main线程上运行
#define DISPATCH_ON_MAIN_THREAD(mainQueueBlock)     dispatch_async(dispatch_get_main_queue(), mainQueueBlock);

#endif /* LYMacros_h */
