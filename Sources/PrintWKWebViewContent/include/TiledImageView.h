//
//  TiledImageView.h
//  iPhemeris
//
//  Created by Clifford Ribaudo on 12/21/20.
//  Copyright © 2021 Clifford Ribaudo. MIT License

#import <Foundation/Foundation.h>

#if TARGET_OS_OSX
#import <AppKit/AppKit.h>
#   define _MACOS_
#elif TARGET_OS_IOS
#import <UIKit/UIKit.h>
#   define _IOS_
#endif

#ifdef _MACOS_
    #define IMAGE_OBJ       NSImage
    #define VIEW_OBJ        NSView
    #define PRINTINFO_OBJ   NSPrintInfo
#else
    #define IMAGE_OBJ       UIImage
    #define VIEW_OBJ        UIView
    #define PRINTINFO_OBJ   UIPrintInfo
#endif

@interface TiledImageView : VIEW_OBJ
{
    NSArray *_imageTiles;
}
-(void)printWithPrintInfo:(PRINTINFO_OBJ *)pi;
-(instancetype)initWithFrame:(CGRect)frame imageTiles:(NSArray<NSArray *> *)imageTiles;

#ifdef _IOS_
-(UIImage *)imageFromView;
-(UIImage *)imageFromViewAtScale:(CGFloat)scale;
#endif
@end
