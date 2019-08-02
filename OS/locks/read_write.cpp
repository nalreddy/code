boost::shared_mutex _access;
void reader()
{
      // get shared access
      boost::shared_lock<boost::shared_mutex> lock(_access);

        // now we have shared access
}

void writer()
{
      // get upgradable access
      boost::upgrade_lock<boost::shared_mutex> lock(_access);

        // get exclusive access
        boost::upgrade_to_unique_lock<boost::shared_mutex> uniqueLock(lock);
          // now we have exclusive access
}

//
boost::shared_mutex _access;
void reader()
{
      boost::shared_lock< boost::shared_mutex > lock(_access);
        // do work here, without anyone having exclusive access
}

void conditional_writer()
{
      boost::upgrade_lock< boost::shared_mutex > lock(_access);
        // do work here, without anyone having exclusive access

        if (something) {
                boost::upgrade_to_unique_lock< boost::shared_mutex > uniqueLock(lock);
                    // do work here, but now you have exclusive access
                  }

          // do more work here, without anyone having exclusive access
}

void unconditional_writer()
{
      boost::unique_lock< boost::shared_mutex > lock(_access);
        // do work here, with exclusive access
}
