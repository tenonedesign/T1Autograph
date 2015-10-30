#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>



@interface T1SignaturePoint : NSObject <NSCopying>

@property (nonatomic, assign) CGPoint location;			// relative to enclosing view
@property (nonatomic, assign) CGPoint velocity;			// instantaneous velocity of pen
@property (nonatomic, assign) CGPoint acceleration;		// instantaneous acceleration of pen
@property (nonatomic, assign) NSTimeInterval timestamp;	// timestamp of point
@property (nonatomic, assign) float azimuthAngle;		// as defined in UITouch.h relative to enclosing view
@property (nonatomic, assign) float altitudeAngle;		// as defined in UITouch.h defaults to M_PI_2
@property (nonatomic, assign) float pressure;			// 0.0f - 1.0f where 1.0f is the UITouch maximumPossibleForce
@property (nonatomic, assign) float diameter;			// computed diameter of point used for drawing stroke
@property (nonatomic, assign) NSUInteger id;			// unique identifier

@end
