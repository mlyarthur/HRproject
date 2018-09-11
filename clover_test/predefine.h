#pragma once
#include <cassert>
#include <list>
#include <vector>
#include <set>
#include <map>

extern double start_time;
extern double end_time;
extern size_t minval_ =0;
extern size_t gap_ =20;
extern size_t bins_=8;

enum period { day, night, allday, rest };
enum fatigue { fmild = 1, fsevere = 2 };
enum pressure { pmild = 1, psevere = 2 };
enum isScoop { scoop = 1, non_scoop = 2 };
enum s_type { hr, hr_diff, hr_f, hr_p, hr_s, hp, hr_day, hr_night, hr_ad, hr_rest };


