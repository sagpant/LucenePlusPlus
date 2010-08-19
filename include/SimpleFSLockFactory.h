/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2010 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FSLockFactory.h"
#include "Lock.h"

namespace Lucene
{
	/// Implements {@link LockFactory} using {@link File#createNewFile()}.
	/// @see LockFactory
	class LPPAPI SimpleFSLockFactory : public FSLockFactory
	{
	public:
		/// Create a SimpleFSLockFactory instance, with null (unset) lock directory. When you pass this factory 
		/// to a {@link FSDirectory} subclass, the lock directory is automatically set to the directory itself. 
		/// Be sure to create one instance for each directory your create!
		SimpleFSLockFactory();
		
		/// Instantiate using the provided directory name.
		/// @param lockDir where lock files should be created.
		SimpleFSLockFactory(const String& lockDir);
		
		virtual ~SimpleFSLockFactory();
		
		LUCENE_CLASS(SimpleFSLockFactory);
			
	public:
		/// Return a new Lock instance identified by lockName.
		virtual LockPtr makeLock(const String& lockName);
		
		/// Attempt to clear (forcefully unlock and remove) the specified lock.
		virtual void clearLock(const String& lockName);
	};
	
	class LPPAPI SimpleFSLock : public Lock
	{
	public:
		SimpleFSLock(const String& lockDir, const String& lockFileName);
		virtual ~SimpleFSLock();
		
		LUCENE_CLASS(SimpleFSLock);
			
	public:
		String lockDir;
		String lockFile;
	
	public:
		/// Attempts to obtain exclusive access and immediately return upon success or failure.
		/// @return true if exclusive access is obtained.
		virtual bool obtain();
		
		/// Releases exclusive access.
		virtual void release();
		
		/// Returns true if the resource is currently locked. Note that one must still call {@link #obtain()} 
		/// before using the resource.
		virtual bool isLocked();
		
		/// Returns derived object name.
		virtual String toString();
	};
}
