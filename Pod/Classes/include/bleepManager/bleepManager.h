//
//  bleepManager.h
//  bleepManager
//
//  Copyright (C) 2014 Rainmaker Labs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>
#import "bleepBeacon.h"

@class bleepManager;

@protocol bleepManagerDelegate <NSObject>

@optional

-(void)beaconManager:(bleepManager *)manager didStartMonitoringForRegion:(CLRegion *)region;
-(void)beaconManager:(bleepManager *)manager monitoringDidFailForRegion:(CLRegion *)region withError:(NSError *)error;
-(void)beaconManager:(bleepManager *)manager didRangeBeacons:(NSArray *)beacons inRegion:(CLBeaconRegion *)region;
-(void)beaconManager:(bleepManager *)manager rangingBeaconsDidFailForRegion:(CLBeaconRegion *)region withError:(NSError *)error;
-(void)beaconManager:(bleepManager *)manager didEnterRegion:(CLRegion *)region;
-(void)beaconManager:(bleepManager *)manager didExitRegion:(CLRegion *)region;
-(void)beaconManager:(bleepManager *)manager didDetermineState:(CLRegionState)state forRegion:(CLRegion *)region;

-(void)respondToShortlistedBeacons:(NSArray *)beacons;
//-(void)respondToBeaconOut:(NSDictionary *)seldict;

-(void)appendTextForDemoPurposes:(NSString *)displayTxt;
-(void)updateTextForDemoPurposes:(NSString *)displayTxt;

-(void)beginBackgroundUpdateTaskBleep;
-(void)endBackgroundUpdateTaskBleep;

@end

@interface bleepManager : NSObject <CLLocationManagerDelegate>

@property (nonatomic, weak) id <bleepManagerDelegate> delegate;

@property (nonatomic, strong) NSString *apiKey;
@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong, readonly) NSString *userName;

@property (nonatomic, readonly) BOOL reportsBatteryLevel;
@property (nonatomic) BOOL shouldOnlyRespondToNearest;
@property (nonatomic) BOOL shouldOnlyLogNearest;
@property (nonatomic) float timeBeforeCountedAsOut;
@property (nonatomic) float maxTimeForBackgroundUpdate;
@property (nonatomic) BOOL notifyEntryStateOnDisplay;
@property (nonatomic) BOOL autoStart;
@property (nonatomic) BOOL showDebugLogs;
@property (nonatomic) BOOL forceBmsSync;

+(bleepManager *)sharedInstance;

- (void)setApiKey:(NSString *)apiKey;
- (void)setApiKey;
- (void)setUserId:(NSString *)userId;
- (void)setUserId:(NSString *)userId andUserName:(NSString *)userName;
- (void)resetUserId;

- (void)setIsBatteryLevelReportingSupported:(BOOL)yesorno;
- (void)setShouldOnlyRespondToNearest:(BOOL)yesorno;
- (void)setShouldOnlyLogNearest:(BOOL)yesorno;
- (void)setTimeBeforeCountedAsOut:(float)floatIntv;
- (void)setNotifyEntryStateOnDisplay:(BOOL)yesorno;
- (void)setAutoStart:(BOOL)yesorno;
- (void)setShowDebugLogs:(BOOL)yesorno;
- (void)setForceBmsSync:(BOOL)yesorno;

- (void)initBleepManager;

- (void)startMonitoringSignificantLocationChanges;
- (void)startBleepDiscovery;
- (void)stopBleepDiscovery;
- (void)pauseBleepDiscovery;
- (void)resumeBleepDiscovery;

- (NSSet *)getMonitoredRegions;

- (void)clearTimeIntervalLogsForBeaconDetection;
- (void)clearTimeIntervalLogForBeaconDetection;
- (void)clearEntryTimeIntervalLogForBeaconDetection;
- (void)clearLiveTimeIntervalLogForBeaconDetection;

- (BOOL)checkUserActivityValidity:(NSString *)keyUserActivity withInterval:(int)timeInterval logThis:(BOOL)logthis;
- (void)storeActivityTimestamp:(NSString *)keyUserActivity;
- (void)resetAdLogsPrefixed:(NSString *)prefix;
- (void)eraseTriggerLog:(bleepBeacon *)beacon;

- (void)addExtraLogwithType:(NSString *)type andValue:(NSString *)value;
- (void)addExtraLogwithBeacon:(bleepBeacon *)beacon andType:(NSString *)type andValue:(NSString *)value;
- (void)addExtraLogwithBeaconTag:(NSString *)beaconTag andBeaconId:(NSNumber *)beaconId andType:(NSString *)type andValue:(NSString *)value;

- (void)applicationDidEnterBackground;
- (void)didFinishLaunchingWithOptions;
- (void)applicationDidBecomeActive;
- (void)fetchWithCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;

- (void)askForLocPermission;

@end
