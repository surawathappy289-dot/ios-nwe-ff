# Hook System Improvements (แก้ระบบ hook)

## Summary of Fixes

The Zexis inline hook system has been enhanced with robust error handling and thread safety improvements.

### Issues Fixed

#### 1. **Incorrect ZexisUnhook() Parameter (Critical)**
- **Problem**: Hook removal was passing function pointer instead of address
  ```c
  // BEFORE (Wrong)
  ZexisUnhook((void *)switchfast);  // Passes function address
  
  // AFTER (Correct)
  ZexisUnhook(switchAddr);  // Passes original hook address
  ```
- **Impact**: Could fail to properly remove hooks, causing memory leaks and unintended behaviors

#### 2. **Missing Error Handling in Zexis()**
- **Added**: Validation of parameters (count, address arrays, function arrays)
- **Added**: Return code checking on all kernel calls:
  - `mach_port_allocate()`
  - `mach_port_insert_right()`
  - `task_set_exception_ports()`
  - `task_threads()`
- **Added**: Proper cleanup on initialization failure
- **Improvement**: Now returns `false` on any failure instead of silently continuing

#### 3. **Missing Error Handling in ZexisUnhook()**
- **Added**: Null pointer validation
- **Added**: Return code checking on all kernel calls
- **Added**: Verification that address was actually found before reporting success
- **Added**: Proper error handling for `task_threads()` failures

#### 4. **Thread Detach Missing**
- **Problem**: Exception handler thread was created but not detached
- **Fixed**: Added `pthread_detach(thread)` to prevent zombie threads
- **Impact**: Prevents thread resource leaks

#### 5. **Incorrect Variable Initialization**
- **Problem**: `thread_count` was initialized to `ARM_DEBUG_STATE64_COUNT` (constant) instead of being output parameter
- **Fixed**: Now properly receives thread count from `task_threads()`
- **Impact**: Ensures all threads are properly updated

#### 6. **Hook Address Tracking**
- **Problem**: Static addresses weren't preserved for unhooking
- **Fixed**: Now store hook addresses in static variables:
  ```c
  static void *switchAddr = NULL;  // Tracks hook address
  static void *guestAddr = NULL;   // Tracks hook address
  ```
- **Impact**: Enables reliable hook cleanup

#### 7. **Missing Return Code Validation in Draw.mm**
- **Added**: Check `Zexis()` return value before marking hook as active
- **Added**: Revert UI state on hook failure
- **Added**: NSLog for debugging unhook failures
- **Impact**: Better error visibility and UI consistency

### Files Modified

1. **hook/hook.c** (hook.c)
   - Enhanced `Zexis()` with comprehensive error checking
   - Enhanced `ZexisUnhook()` with validation and error handling
   - Added thread detach to prevent resource leaks

2. **Draw.mm**
   - Fixed `toggleFastSwitch:` to use address instead of function pointer
   - Fixed `toggleResetGuest:` to use address instead of function pointer
   - Added address tracking with static variables
   - Added return value checking for hook operations
   - Added error logging for debugging

### Benefits

✅ **Reliability**: Hooks now properly install and uninstall  
✅ **Stability**: Error handling prevents silent failures  
✅ **Debugging**: NSLog output shows hook operation status  
✅ **Resource Safety**: No thread or memory leaks  
✅ **UI Consistency**: Switch state reverts if hook fails  

### Testing Recommendations

1. Toggle FastSwitch feature on/off multiple times
2. Toggle Guest Reset feature on/off multiple times
3. Monitor system logs for "Failed to unhook" messages
4. Verify no crashes during hook operations
5. Check for resource usage stability over time

### Technical Details

- **Hook Method**: ARM64 hardware breakpoints via Mach exception handling
- **Max Hooks**: 6 concurrent hooks (hardware limitation)
- **Thread Safety**: Exception handler thread handles all threads
- **Cleanup**: Hooks can be safely removed at runtime
