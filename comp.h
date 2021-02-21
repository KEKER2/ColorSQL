#pragma once
#include "record.h"
using namespace std;
bool cmp_platform(record a, record b) {
    return lexicographical_compare(a.PLATFORM.begin(),a.PLATFORM.end(),b.PLATFORM.begin(),b.PLATFORM.end());
}
bool cmp_name(record a, record b) {
    return lexicographical_compare(a.NAME.begin(),a.NAME.end(),b.NAME.begin(),b.NAME.end());
}
bool cmp_followers(record a, record b) {
    return (a.FOLLOWERS < b.FOLLOWERS);
}
bool cmp_uuid(record a, record b) {
    return lexicographical_compare(a.UUID.begin(),a.UUID.end(),b.UUID.begin(),b.UUID.end());
}
bool is_same_uuid(record a) {
    return (a.UUID == VALUE);
}