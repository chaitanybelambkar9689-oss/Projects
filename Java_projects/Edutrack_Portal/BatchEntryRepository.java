package com.marvellous.Marvellousfullstack.Repository;

import com.marvellous.Marvellousfullstack.Entity.BatchEntry;
import org.bson.types.ObjectId;
import org.springframework.data.mongodb.repository.MongoRepository;

public interface BatchEntryRepository extends MongoRepository<BatchEntry, ObjectId>
{

}
