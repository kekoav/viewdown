//
//  AppDelegate.h
//  ViewDown
//
//  Created by martin on 02/02/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>

@interface AppDelegate : NSObject <NSApplicationDelegate, NSWindowDelegate>
{
    @private
    
    BOOL finishedStarting;
    NSString *toLaunchWhenFinished;
    
    NSFileManager* fm;
    NSMutableArray* pathsToWatch;
    NSNumber* lastEventId;
    FSEventStreamRef stream;

    NSString *monitored;
    NSDate *lastModified;
    
    NSDate *lastBuilt;
    
    NSString* tmpFile;
    
    NSString* markdownPath;
    
    NSData *head;
    NSData *tail;
    
    NSPoint savedScrollPosition;
    BOOL scrollToLast;
    
    
    
} 

@property (assign) IBOutlet NSWindow *window;
@property (strong) IBOutlet NSView *view;
@property (strong) IBOutlet WebView *web;

-(void)setCurrent:(NSURL*)url;

-(BOOL)application:(NSApplication *)theApplication openFile:(NSString *)filename;
-(void)openDocument:(id)sender;

- (void)initializeEventStream:(NSURL*)file;
- (void)scanDir:(NSString*)path lastEventId:(uint64_t)eventId;
- (void)buildMarkdown:(BOOL)savePosition;

// control dragging to webview
-(NSUInteger)webView:(WebView *)webView dragDestinationActionMaskForDraggingInfo:(id<NSDraggingInfo>)draggingInfo;
- (void)webView:(WebView *)webView willPerformDragDestinationAction:(WebDragDestinationAction)action forDraggingInfo:(id <NSDraggingInfo>)draggingInfo;
- (void)webView:(WebView *)sender didFinishLoadForFrame:(WebFrame *)frame;


@end
