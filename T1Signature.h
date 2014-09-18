#import <UIKit/UIKit.h>



// Definition of T1Signature object returned by autograph:didCompleteWithSignature:

@interface T1Signature : NSObject


@property (strong, nonatomic) NSData *imageData;		// raw image data of the non clipped signature
@property (strong, nonatomic) UIImageView *imageView;	// retina-ready view of signature
@property (strong, nonatomic) NSData *pdfData;			// raw pdf data of the non clipped signature
@property (assign, nonatomic) CGPDFDocumentRef pdf;		// signature in pdf format (retained only by T1Signature)
@property (strong, nonatomic) NSString *hashString;		// hash string (user-defined or auto-generated)
@property (assign)            CGRect frame;				// location and size of signature within the enclosing view
@property (assign)            NSTimeInterval timestamp;	// timestamp of signature
@property (strong, nonatomic) NSArray *rawPoints;		// array of strokes, each containing an array of data

// A note about rawPoints:
// Each point is a CGRect {{x,y},{stroke width, unique identifier}}.
// Location data in rawPoints includes no smoothing.  Each point is relative to enclosing view.
// Also note rawPoints is not clipped to the enclosing view and may therefore be located outside of it.

@end
