/*****************************************************************************
 * SegmentInfoCommon.h: Implement the common part for both SegmentInfoDefault
 *                      and SegmentInfo
 *****************************************************************************
 * Copyright (C) 1998-2007 VLC authors and VideoLAN
 * $Id$
 *
 * Authors: Hugo Beauzée-Luyssen <beauze.h@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef SEGMENTINFOCOMMON_H
#define SEGMENTINFOCOMMON_H

#include <string>
#include <list>
#include <ctime>
#include "ICanonicalUrl.hpp"
#include "Properties.hpp"

namespace dash
{
    namespace mpd
    {
        class Segment;
        class SegmentTimeline;

        template<class T> class Initializable
        {
            public:
                Initializable()
                {
                    initialisationSegment.Set(NULL);
                }
                ~Initializable()
                {
                    delete initialisationSegment.Get();
                }
                Property<T *> initialisationSegment;
        };

        class SegmentInfoCommon : public ICanonicalUrl,
                                  public Initializable<Segment>
        {
            public:
                SegmentInfoCommon( ICanonicalUrl *parent = NULL );
                virtual ~SegmentInfoCommon();
                time_t                  getDuration() const;
                void                    setDuration( time_t duration );
                int                     getStartIndex() const;
                void                    setStartIndex( int startIndex );
                void                    appendBaseURL( const std::string& url );
                const SegmentTimeline*  getSegmentTimeline() const;
                void                    setSegmentTimeline( const SegmentTimeline *segTl );
                virtual Url             getUrlSegment() const; /* impl */

            private:
                time_t                  duration;
                int                     startIndex;
                std::list<std::string>  baseURLs;
                const SegmentTimeline*  segmentTimeline;
        };
    }
}

#endif // SEGMENTINFOCOMMON_H
