/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2010 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ValueSource.h"
#include "DocValues.h"

namespace Lucene
{
	/// Obtains the ordinal of the field value from the default Lucene {@link FieldCache} using getStringIndex()
	/// and reverses the order.
	///
	/// The native lucene index order is used to assign an ordinal value for each field value.
	///
	/// Field values (terms) are lexicographically ordered by unicode value, and numbered starting at 1.  Example 
	/// of reverse ordinal (rord):
	///
	/// If there were only three field values: "apple","banana","pear" then rord("apple")=3, rord("banana")=2, 
	/// ord("pear")=1
	///
	/// WARNING: rord() depends on the position in an index and can thus change when other documents are inserted 
	/// or deleted, or if a MultiSearcher is used. 
	///
	/// NOTE: with the switch in 2.9 to segment-based searching, if {@link #getValues} is invoked with a composite 
	/// (multi-segment) reader, this can easily cause double RAM usage for the values in the FieldCache.  It's
	/// best to switch your application to pass only atomic (single segment) readers to this API.
	class LPPAPI ReverseOrdFieldSource : public ValueSource
	{
	public:
		/// Constructor for a certain field.
		/// @param field field whose values reverse order is used.  
		ReverseOrdFieldSource(const String& field);		
		virtual ~ReverseOrdFieldSource();
	
		LUCENE_CLASS(ReverseOrdFieldSource);
	
	protected:
		String field;
	
	public:
		virtual String description();
		virtual DocValuesPtr getValues(IndexReaderPtr reader);
		virtual bool equals(LuceneObjectPtr other);
		virtual int32_t hashCode();
	};
	
	class LPPAPI ReverseOrdDocValues : public DocValues
	{
	public:
		ReverseOrdDocValues(ReverseOrdFieldSourcePtr source, Collection<int32_t> arr, int32_t end);
		virtual ~ReverseOrdDocValues();
	
		LUCENE_CLASS(ReverseOrdDocValues);
	
	protected:
		ReverseOrdFieldSourceWeakPtr _source;
		Collection<int32_t> arr;
		int32_t end;
	
	public:
		virtual double doubleVal(int32_t doc);
		virtual int32_t intVal(int32_t doc);
		virtual String strVal(int32_t doc);
		virtual String toString(int32_t doc);
		virtual CollectionValue getInnerArray();
	};
}
