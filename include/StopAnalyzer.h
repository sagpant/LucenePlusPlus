/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2010 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Analyzer.h"

namespace Lucene
{
	/// Filters {@link LetterTokenizer} with {@link LowerCaseFilter} and {@link StopFilter}.
	///
	/// You must specify the required {@link Version} compatibility when creating StopAnalyzer: As of 2.9, position 
	/// increments are preserved
	class LPPAPI StopAnalyzer : public Analyzer
	{
	public:
		/// Builds an analyzer which removes words in {@link #ENGLISH_STOP_WORDS_SET}.
		StopAnalyzer(LuceneVersion::Version matchVersion);
		
		/// Builds an analyzer with the stop words from the given set.
		StopAnalyzer(LuceneVersion::Version matchVersion, HashSet<String> stopWords);
		
		/// Builds an analyzer with the stop words from the given file.
		StopAnalyzer(LuceneVersion::Version matchVersion, const String& stopwordsFile);
		
		/// Builds an analyzer with the stop words from the given reader.
		StopAnalyzer(LuceneVersion::Version matchVersion, ReaderPtr stopwords);
		
		virtual ~StopAnalyzer();
		
		LUCENE_CLASS(StopAnalyzer);
	
	protected:
		HashSet<String> stopWords;
		bool enablePositionIncrements;
	
		static const wchar_t* _ENGLISH_STOP_WORDS_SET[];
	
	public:
		/// An unmodifiable set containing some common English words that are usually not useful for searching.
		static HashSet<String> ENGLISH_STOP_WORDS_SET();
	
	public:
		virtual TokenStreamPtr tokenStream(const String& fieldName, ReaderPtr reader);
		virtual TokenStreamPtr reusableTokenStream(const String& fieldName, ReaderPtr reader);
	};
	
	/// Filters LowerCaseTokenizer with StopFilter.
	class LPPAPI StopAnalyzerSavedStreams : public LuceneObject
	{
	public:
		virtual ~StopAnalyzerSavedStreams();
		
		LUCENE_CLASS(StopAnalyzerSavedStreams);
	
	public:
		TokenizerPtr source;
		TokenStreamPtr result;
	};
}
