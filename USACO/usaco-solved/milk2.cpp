#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/***
 * milk2
 */
bool less_pair(const pair<int,int> & m1, const pair<int,int> & m2) {
        return m1.first < m2.first;
}
typedef vector<pair<int,int> > interval;
void milk_cow() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
	vector<pair<int,int> > intervals;
	vector<pair<int,int> > intervals_intersected;
	int max_len=0, max_gap=0;
	pair<int,int> tmp;
	int c = 0;
	fin >> c;
	for(; c; c--) {
		fin >> tmp.first >> tmp.second;
		intervals.push_back(tmp);
	}
	sort(intervals.begin(), intervals.end(), less_pair);
	interval::iterator it1 = intervals.begin();
	interval::iterator it2;
	interval::iterator it_end = intervals.end();
	for( ; it1 != it_end; ) {
		tmp = *it1;
		it2 = it1;
		++it2;// it2++ = it1?
		for(; it2 != it_end; ++it2 ) { /* when iterating throw an ordered sequence, using index might be better */
			if( (*it2).first > tmp.second ) break;
			if( (*it2).second > tmp.second ) tmp.second = (*it2).second;
		}
		intervals_intersected.push_back(tmp);
		it1 = it2;
	}
	it1 = intervals_intersected.begin();
	it2 = it1;
	it_end = intervals_intersected.end();
	for( ; it1 != it_end; ++it1 ) {
		max_gap = std::max(max_gap, (*it1).first - (*it2).second);
		max_len = std::max(max_len, (*it1).second - (*it1).first);
		it2 = it1;
	}
	fout << max_len <<" " << max_gap <<endl;
}



/* sort the starting and ending times, then go through them from
 start to finish, keeping track of how many farmers are milking
 between each "event" (a single farmer starting and stopping). */

#include <fstream.h>
#include <stdlib.h>

struct event {
	long seconds; /* seconds since 5 am */
	signed char ss; /* start = 1, stop = -1 (delta number of farmers milking)
	 */
};

int eventcmp(const event *a, const event *b) {
	if (a->seconds != b->seconds)
		return (a->seconds - b->seconds); /* 300 before 500 */
	return (b->ss - a->ss); /* 1 (start) before -1 (stop) */
}

int milk2() {
	ifstream in;
	ofstream out;

	in.open("milk2.in");
	out.open("milk2.out");

	int num_intervals, num_events, i;
	event events[5000 * 2];

	in >> num_intervals;
	num_events = num_intervals * 2;
	for (i = 0; i < num_intervals; ++i) {
		in >> events[2 * i].seconds;
		events[2 * i].ss = 1;
		in >> events[2 * i + 1].seconds;
		events[2 * i + 1].ss = -1;
	}

	qsort(events, num_events, sizeof(event),
			(int (*)(const void*, const void*)) eventcmp);

	/* for (i = 0; i < num_events; ++i)
	   out << events[i].seconds
	   	   << (events[i].ss == 1 ? " start" : " stop") << endl; */

	int num_milkers = 0, was_none = 1;
	int longest_nomilk = 0, longest_milk = 0;
	int istart, ilength;

	for (i = 0; i < num_events; ++i) {
		num_milkers += events[i].ss;

		if (!num_milkers && !was_none) {
			/* there are suddenly no milkers. */
			ilength = (events[i].seconds - istart);
			if (ilength > longest_milk)
				longest_milk = ilength;
			istart = events[i].seconds;
		} else if (num_milkers && was_none) {
			/* there are suddenly milkers. */
			if (i != 0) {
				ilength = (events[i].seconds - istart);
				if (ilength > longest_nomilk)
					longest_nomilk = ilength;
			}
			istart = events[i].seconds;
		}
		was_none = (num_milkers == 0);
	}

	out << longest_milk << " " << longest_nomilk << endl;

	return 0;
}


