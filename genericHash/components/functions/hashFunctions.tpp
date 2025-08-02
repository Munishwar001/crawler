#pragma once
#include <iostream>
#include "../hash.h"
using namespace std;

template <typename keyType, typename valueType>
void Hash<keyType, valueType>::insertion(keyType key, valueType value)
{
    reSize();
    int index = getIndex(key, size);
    Node<keyType, valueType> *newNode = new Node<keyType, valueType>(key, value);
    if (head[index] == NULL)
    {
        head[index] = newNode;
        noOfElements++;
        return;
    }
    Node<keyType, valueType> *current = head[index];
    while (current->next != NULL && current->key != key)
    {
        current = current->next;
    }
    if (current->key == key)
    {
        cout << "key Already Exist" << endl;
        current->value = value;
        return;
    }
    // noOfElements++;
    current->next = newNode;
}

template <typename keyType, typename valueType>
void Hash<keyType, valueType>::reSize()
{
    int percentage = (noOfElements * 100) / size;
    if (percentage < 75)
    {
        return;
    }
    cout << "Resizing the Hash Table" << endl;
    Node<keyType, valueType> **bucket = head;
    head = new Node<keyType, valueType> *[size * 2];
    int temp = size;
    size = size * 2;
    for (int i = 0; i < size; i++)
    {
        head[i] = NULL;
    }
    for (int i = 0; i < temp; i++)
    {
        while (bucket[i])
        {
            insertion(bucket[i]->key, bucket[i]->value);
            Node<keyType, valueType> *temp = bucket[i];
            bucket[i] = bucket[i]->next;
            delete temp;
        }
    }
    delete[] bucket;
}

template <typename keyType, typename valueType>
void Hash<keyType, valueType>::search(keyType key)
{
    int index = getIndex(key, size);
    if (head[index] == NULL)
    {
        cout << "Element not present";
        return;
    }
    Node<keyType, valueType> *current = head[index];
    while (current)
    {
        if (current->key == key)
        {
            cout << "value for your key: " << key << " is " << current->value << endl;
            return;
        }
        current = current->next;
    }
    cout << "Element not present" << endl;
    return;
}

template <typename keyType, typename valueType>
void Hash<keyType, valueType>::deleteElement(keyType key)
{
    int index = getIndex(key, size);
    if (head[index] == NULL)
    {
        cout << "The Element is already not exist";
        return;
    }
    if (head[index]->key == key)
    {
        head[index] = head[index]->next;
        cout << "Element with the key " << key << " is deleted" << endl;
        return;
    }
    Node<keyType, valueType> *current = head[index];
    Node<keyType, valueType> *prev = NULL;
    while (current)
    {
        if (current->key == key)
        {
            cout << "element with the key: " << key << " is Deleted";
            prev->next = current->next;
            return;
        }
        prev = current;
        current = current->next;
    }
    return;
}

template <typename keyType, typename valueType>
void Hash<keyType, valueType>::display()
{
    for (int i = 0; i < size; i++)
    {
        Node<keyType, valueType> *current = head[i];
        while (current)
        {
            cout << "key " << current->key << " value " << current->value << endl;
            current = current->next;
        }
    }
    return;
}

template <typename keyType, typename valueType>
Hash<keyType, valueType>::~Hash()
{
    for (int i = 0; i < size; i++)
    {
        Node<keyType, valueType> *current = head[i];
        while (current != nullptr)
        {
            Node<keyType, valueType> *temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] head;
}
