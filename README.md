# Print-All-WKWebView-Content
Prints all the on and offscreen content of a WKWebView and correctly paginates. Works on both MacOS and iOS

Usage Examples: I subclassed WKWebView and then added print functions directly to the subclass. This may not be suitable for your projects but see that code for examples of how to use the the rest of the solution on both iOS and MacOS.

```
-(void)print:(id)sender
{
    // Set this as per your needs
    NSPrintInfo *pInfo = [NSPrintInfo sharedPrintInfo];
    pInfo.verticallyCentered = YES;
    pInfo.horizontallyCentered = NO;
    pInfo.horizontalPagination = NSAutoPagination;
    pInfo.verticalPagination = NSAutoPagination;
    pInfo.orientation = NSPaperOrientationLandscape;
    pInfo.bottomMargin = 30;
    pInfo.topMargin = 30;
    pInfo.leftMargin = 30;
    pInfo.rightMargin = 30;
    pInfo.scalingFactor = .60;
    
    [_webView HTMLPageMetrics:^(CGSize htmlSize, CGSize visibleSize, NSError *error)
    {
        self->_imgTileData = [NSMutableArray new];
 
        [self->_webView imageTilesForHTMLPage:htmlSize visbleRect:visibleSize imgData:self->_imgTileData completionHandler:^(NSError *error) {
            if(!error) {
                TiledImageView *tiv = [[TiledImageView alloc] initWithFrame:CGRectMake(0,0,htmlSize.width,htmlSize.height) imageTiles:self->_imgTileData];
                [tiv printWithPrintInfo:pInfo];
            }
        }];
    }
}
```
