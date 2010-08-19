/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2010 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "DocFieldConsumerPerField.h"

namespace Lucene
{
	class LPPAPI DocFieldConsumersPerField : public DocFieldConsumerPerField
	{
	public:
		DocFieldConsumersPerField(DocFieldConsumersPerThreadPtr perThread, DocFieldConsumerPerFieldPtr one, DocFieldConsumerPerFieldPtr two);
		virtual ~DocFieldConsumersPerField();
		
		LUCENE_CLASS(DocFieldConsumersPerField);
			
	public:
		DocFieldConsumerPerFieldPtr one;
		DocFieldConsumerPerFieldPtr two;
		DocFieldConsumersPerThreadWeakPtr _perThread;
	
	public:
		/// Processes all occurrences of a single field
		virtual void processFields(Collection<FieldablePtr> fields, int32_t count);
		
		virtual void abort();
	};
}
