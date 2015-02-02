//
//  bleepBeacon.h
//  bleepManager
//
//  Copyright (C) 2014 Rainmaker Labs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLRegion.h>
#import <CoreLocation/CLAvailability.h>

@class bleepBeacon;

@interface bleepBeacon : NSObject<NSCopying>

/*
 *  proximityUUID
 *
 *  Discussion:
 *    Proximity identifier associated with the beacon.
 *
 */
@property (strong, nonatomic) NSUUID *proximityUUID;

/*
 *  major
 *
 *  Discussion:
 *    Most significant value associated with the beacon.
 *
 */
@property (strong, nonatomic) NSNumber *major;

@property (strong, nonatomic) NSNumber *batteryPower;

/*
 *  minor
 *
 *  Discussion:
 *    Least significant value associated with the beacon.
 *
 */
@property (strong, nonatomic) NSNumber *minor;

/*
 *  proximity
 *
 *  Discussion:
 *    Proximity of the beacon from the device.
 *
 */
@property (assign, nonatomic) CLProximity proximity;

/*
 *  accuracy
 *
 *  Discussion:
 *    Represents an one sigma horizontal accuracy in meters where the measuring device's location is
 *    referenced at the beaconing device. This value is heavily subject to variations in an RF environment.
 *    A negative accuracy value indicates the proximity is unknown.
 *
 */
@property (assign, nonatomic) CLLocationAccuracy accuracy;

/*
 *  rssi
 *
 *  Discussion:
 *    Received signal strength in decibels of the specified beacon.
 *    This value is an average of the RSSI samples collected since this beacon was last reported.
 *
 */
@property (assign, nonatomic) NSInteger rssi;

@property (strong, nonatomic) NSDictionary* dict;
@property (strong, nonatomic) NSString* type;
@property (strong, nonatomic) NSNumber *beaconId;
@property (strong, nonatomic) NSString* tag;
@property (strong, nonatomic) NSString* ruleId;
@property (assign, nonatomic) float timeInt;
@property (assign, nonatomic) float timeDur;
@property (assign, nonatomic) int isExit;

@property (assign, nonatomic) int days;
@property (strong, nonatomic) NSString *startDate;
@property (strong, nonatomic) NSString *endDate;
@property (strong, nonatomic) NSString *startTime;
@property (strong, nonatomic) NSString *endTime;
@property (assign, nonatomic) int isLive;

@property (strong, nonatomic) NSString *attStr;
@property (strong, nonatomic) NSString *commID;

@end
