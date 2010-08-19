/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2010 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "LuceneObject.h"

namespace Lucene
{
	/// Utility class for folding character case.
	class LPPAPI CharFolder : public LuceneObject
	{
	public:
		virtual ~CharFolder();
		LUCENE_CLASS(CharFolder);
	
	protected:
		static bool lowerCache;
		static bool upperCache;
		static wchar_t lowerChars[CHAR_MAX - CHAR_MIN + 1];
		static wchar_t upperChars[CHAR_MAX - CHAR_MIN + 1];
	
	public:
		static wchar_t toLower(wchar_t ch);
		static wchar_t toUpper(wchar_t ch);
		
		template <class ITER>
		static void toLower(ITER first, ITER last)
		{
			fillLower();
			for (; first != last; ++first)
				*first = toLower(*first);
		}
		
		template <class ITER>
		static void toUpper(ITER first, ITER last)
		{
			fillUpper();
			for (; first != last; ++first)
				*first = toUpper(*first);
		}
	
	protected:
		static void fillLower();
		static void fillUpper();
	};
}
