// Copyright 2008 Cyrus Najmabadi
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

@interface Pulser : NSObject {
    id target;
    SEL action;
    NSTimeInterval pulseInterval;

    NSDate* lastPulseTime;
}

@property (retain) id target;
@property SEL action;
@property NSTimeInterval pulseInterval;
@property (retain) NSDate* lastPulseTime;

+ (Pulser*) pulserWithTarget:(id) target
                      action:(SEL) action
               pulseInterval:(NSTimeInterval) pulseInterval;

- (void) forcePulse;
- (void) tryPulse;

@end