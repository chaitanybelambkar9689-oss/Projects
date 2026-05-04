package com.marvellous.Marvellousfullstack.Service;

import com.marvellous.Marvellousfullstack.Entity.BatchEntry;
import com.marvellous.Marvellousfullstack.Repository.BatchEntryRepository;
import org.bson.types.ObjectId;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.util.List;
import java.util.Optional;

@Component
public class BatchEntryService
{
    @Autowired
    private BatchEntryRepository batchEntryRepository;

    // C : create POST
    public void  savaEntry(BatchEntry batchEntry)
    {
        batchEntryRepository.save(batchEntry);
    }

    // R : Read GET
    public List<BatchEntry> getAll()
    {
        return batchEntryRepository.findAll();
    }

    // R : Read GET
    public Optional<BatchEntry> findById(Object id)
    {
        return batchEntryRepository.findById((ObjectId) id);
    }

    // D : Delete DELETE
    public void deleteById(Object id)
    {
        ObjectId Objectid;
        batchEntryRepository.deleteById((ObjectId) id);
    }

    public void saveEntry(BatchEntry myentry)
    {

    }
}
