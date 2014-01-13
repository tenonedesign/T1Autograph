#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>



@interface T1SignaturePoint : NSObject <NSCopying>

@property (nonatomic, assign) CGPoint location;
@property (nonatomic, assign) CGPoint velocity;
@property (nonatomic, assign) CGPoint acceleration;
@property (nonatomic, assign) NSTimeInterval timestamp;
@property (nonatomic, assign) float pressure;
@property (nonatomic, assign) float diameter;
@property (nonatomic, assign) NSUInteger id;

@end
