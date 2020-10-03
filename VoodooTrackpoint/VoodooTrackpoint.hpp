/*
 * VoodooTrackpoint.hpp
 * VoodooTrackpoint
 *
 * Copyright (c) 2020 Leonard Kleinhans <leo-labs>
 *
 */

#ifndef VoodooTrackpoint_hpp
#define VoodooTrackpoint_hpp

#include <IOKit/IOService.h>
#include "helpers.hpp"
#include "TrackpointDevice.hpp"
#include "VoodooTrackpointMessages.h"

#ifndef __ACIDANTHERA_MAC_SDK
#error "This kext SDK is unsupported. Download from https://github.com/acidanthera/MacKernelSDK"
#error "You can also do 'git clone --depth 1 https://github.com/acidanthera/MacKernelSDK.git'"
#endif

class VoodooTrackpoint : public IOService {
    OSDeclareDefaultStructors(VoodooTrackpoint)
public:
    virtual bool start(IOService *provider) override;
    virtual void stop(IOService *provider) override;
    bool willTerminate(IOService *provider, IOOptionBits options) override;
    
    
private:
    TrackpointDevice *trackpoint;
    
    void unpublishTrackpoint();
    bool publishTrackpoint();
    
    virtual IOReturn message(UInt32 type, IOService* provider, void* argument) override;
};

#endif /* VoodooTrackpoint_hpp */
