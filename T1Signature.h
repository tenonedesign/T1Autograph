#import <UIKit/UIKit.h>



// Definition of T1Signature object returned by autograph:didCompleteWithSignature:

@interface T1Signature : NSObject
{
	UIImageView *imageView;                 // retina-ready view of signature
	NSTimeInterval timestamp;               // timestamp of signature
	NSString *hashString;                   // hash string (user-defined or auto-generated)
	CGRect frame;                           // location and size of signature within the enclosing view
	NSData *imageData;                      // raw image data of the non clipped signature
	NSArray *rawPoints;                     // array of strokes, each containing an array of data points.
	
	// Each point is a CGRect {{x,y},{stroke width, unique identifier}}.
	// Note rawPoints includes no smoothing.  Locations are relative to enclosing view.
	// Also note rawPoints is not clipped to signature bounds.
}

@property (strong, nonatomic) NSData *imageData;
@property (strong, nonatomic) UIImageView *imageView;
@property (strong, nonatomic) NSString *hashString;
@property (assign)            CGRect frame;
@property (strong, nonatomic) NSArray *rawPoints;
@property (assign)            NSTimeInterval timestamp;

@end
