/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2010 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "DocFieldConsumer.h"
#include "DocumentsWriter.h"

namespace Lucene
{
	/// This is just a "splitter" class: it lets you wrap two DocFieldConsumer instances as a single consumer.
	class LPPAPI DocFieldConsumers : public DocFieldConsumer
	{
	public:
		DocFieldConsumers(DocFieldConsumerPtr one, DocFieldConsumerPtr two);
		virtual ~DocFieldConsumers();
		
		LUCENE_CLASS(DocFieldConsumers);
			
	public:
		DocFieldConsumerPtr one;
		DocFieldConsumerPtr two;
		
		Collection<DocFieldConsumersPerDocPtr> docFreeList;
		int32_t freeCount;
		int32_t allocCount;
	
	public:
		virtual void setFieldInfos(FieldInfosPtr fieldInfos);
		
		/// Called when DocumentsWriter decides to create a new segment
		virtual void flush(MapDocFieldConsumerPerThreadCollectionDocFieldConsumerPerField threadsAndFields, SegmentWriteStatePtr state);
		
		/// Called when DocumentsWriter decides to close the doc stores
		virtual void closeDocStore(SegmentWriteStatePtr state);
		
		/// Called when DocumentsWriter is using too much RAM.
		virtual bool freeRAM();
		
		/// Add a new thread
		virtual DocFieldConsumerPerThreadPtr addThread(DocFieldProcessorPerThreadPtr docFieldProcessorPerThread);
		
		DocFieldConsumersPerDocPtr getPerDoc();
		void freePerDoc(DocFieldConsumersPerDocPtr perDoc);
	};
	
	class LPPAPI DocFieldConsumersPerDoc : public DocWriter
	{
	public:
		DocFieldConsumersPerDoc(DocFieldConsumersPtr fieldConsumers);
		virtual ~DocFieldConsumersPerDoc();
		
		LUCENE_CLASS(DocFieldConsumersPerDoc);
			
	protected:
		DocFieldConsumersWeakPtr _fieldConsumers;
	
	public:
		DocWriterPtr one;
		DocWriterPtr two;
	
	public:
		virtual int64_t sizeInBytes();
		virtual void finish();
		virtual void abort();
	};
}
