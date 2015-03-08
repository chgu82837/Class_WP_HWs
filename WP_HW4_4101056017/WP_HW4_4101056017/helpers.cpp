#include "stdafx.h"

DateTime^ UInt2DateTime(UInt64^ tstmp) {
	Double^ tmp = Convert::ToDouble(tstmp);
    return DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind::Utc).AddSeconds(*tmp).Add(DateTime::Now - DateTime::UtcNow);
}
UInt64^ DateTime2UInt(DateTime^ date) {
    TimeSpan^ diff =  %(date->ToUniversalTime() - DateTime(1970, 1, 1));
    return Convert::ToUInt64(diff->TotalSeconds);
}

UInt32^ toUInt32(UInt32^ input)
{
	if(input->GetType() != UInt32::typeid)
		input = Convert::ToUInt32(input);
	return input;
}