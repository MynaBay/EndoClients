//
//  EndoSwiftAPI.h
//  EndoClient
//
//  Created by Kevin Snow on 7/13/17.
//  Copyright © 2015-2017 MynaBay. All rights reserved.
//

#import <UIKit/UIKit.h>

    ///////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////

typedef NS_ENUM(NSInteger, EndoExecutionState) {
    EndoStateUninitialized  = 0,
    EndoStateIdle,
    EndoStateRunning,
};

///////////////////////////////////////////////////////////////////////////////////////
// Start/Stop the Endo service
//
// First call to EndoStartStop will initialize EndoClient regardless of parameter value.
// A valid configuration for shipping is to leave EndoClient in app but don't call EndoStartStop.
// In this configuration, execution state is EndoStateUninitialized and logging is routed to NSLog.
// Use EndoNSLogPassthrough(NO) to prevent uninitialized Endo from writing to NSLog.
//
void EndoStartStop(BOOL yesToStart_noToStop);
EndoExecutionState EndoState();

///////////////////////////////////////////////////////////////////////////////////////
// Endo logging functions.
//
// These functions route to NSLog if execution state is EndoStateIdle or EndoStateUninitialized.
// The EndoNSLogPassThrough is honored regardless of the execution state.
//
void EndoLog(NSString* message);
void EndoLogWithCategory(NSString* category, NSString* message);

///////////////////////////////////////////////////////////////////////////////////////
// Endo functions to dump stack traces
//
// These functions route to NSLog if execution state is EndoStateIdle or EndoStateUninitialized.
// The EndoNSLogPassThrough is honored regardless of the execution state.
//
void EndoLogStackTrace(NSString* message);
void EndoLogWithCategoryStackTrace(NSString* category, NSString* message);

///////////////////////////////////////////////////////////////////////////////////////
// Endo function to add an execution block that can be called from the Endo command line.
//
// Add code blocks to be executed via Endo's command line.
// Endo must be in state EndoStateRunning or EndoStateIdle when EndoAddCommand() is called.
// Adding commands to uninitialized Endo are ignored. You can initialize Endo but not
// publish by starting with EndoStartStop(NO).
//
void EndoAddCommand(NSString* cmd, NSString* description, void (^cmdBlock)(NSArray<NSString*>* parameters));

///////////////////////////////////////////////////////////////////////////////////////
// Endo enable local log
//
//  Write Endo logs to a unique file under Documents/ in app's sandbox. Use file system button in Endo to access log.
//
void EndoLocalLogging(BOOL yesToEnable);

///////////////////////////////////////////////////////////////////////////////////////
// Endo NSLog override
//
// Flag to control whether Endo writes to NSLog or not. Still applies on uninitialized Endo.
//
void EndoNSLogPassthrough(BOOL yesToNSLogMessages_noToNot);

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////



