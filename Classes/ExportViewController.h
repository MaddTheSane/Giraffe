//
//  ExportViewController.h
//  Giraffe
//
//  Created by Alex Nichol on 11/5/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PhotoEntry.h"

#import "ANGifEncoder.h"
#import "ANCutColorTable.h"
#import "ANGifNetscapeAppExtension.h"
#import "ANImageBitmapRep.h"
#import "UIImagePixelSource.h"

@interface ExportViewController : UIViewController {
	NSArray * images;
	UILabel * progressStatus;
	UIProgressView * progressView;
	void (^doneCallback)(NSString * file);
}
#ifdef __MAC_10_11
- (instancetype)initWithImages:(NSArray<UIImage*> *)imageArray;
#else
- (instancetype)initWithImages:(NSArray *)imageArray;
#endif
- (void)encodeToFile:(NSString *)fileName callback:(void (^)(NSString * file))callback;

@end
