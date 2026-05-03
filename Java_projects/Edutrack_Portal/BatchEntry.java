package com.marvellous.Marvellousfullstack.Entity;

import lombok.Getter;
import lombok.Setter;
import org.springframework.data.mongodb.core.mapping.Document;

@Document(collection = "BatchDetails")
@Getter
@Setter
public class BatchEntry
{
    private Object id;
    private String name;
    private  int fees;
}