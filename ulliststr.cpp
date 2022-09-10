#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"

ULListStr::ULListStr()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

ULListStr::~ULListStr()
{
    clear();
}

bool ULListStr::empty() const
{
    return size_ == 0;
}

size_t ULListStr::size() const
{
    return size_;
}
void ULListStr::push_back(const std::string& val){
    if(size_ == 0){
        Item* newTail = new Item();
        tail_ = newTail;
        head_ = tail_;
        tail_->first = 0;
        tail_->last = 0;
        tail_->val[0] = val;
        tail_->last++;
        size_++;
    }
    else if(tail_->first == 0 && tail_->last == 10){
        Item* newTail = new Item();
        newTail->prev = tail_;
        tail_->next = newTail;
        tail_ = newTail;
        tail_->first = 0;
        tail_->last = 0;
        tail_->val[0] = val;
        tail_->last++;
        size_++;
    }
    else{
        tail_->val[tail_->last] = val;
        tail_->last++;
    }
}
void ULListStr::push_front(const std::string& val){
    if(size_ == 0){
        Item* newHead = new Item();
        head_ = newHead;
        head_ = tail_;
        head_->first = 10;
        head_->last = 10;
        head_->first--;
        head_->val[9] = val;
        size_++;
    }
    if(head_->first == 0 && head_->last == 10){
        Item* newHead = new Item();
        newHead->next = head_;
        head_->prev = newHead;
        head_ = newHead;
        head_->first = 10;
        head_->last = 10;
        head_->first--;
        head_->val[9] = val;
        size_++;
    }
    else{
        head_->first--;
        head_->val[head_->first] = val;
    }
}
void ULListStr::pop_back(){
    if(tail_->first == 0 && tail_->last == 1){
        tail_->val[0].erase();
        tail_->last--;
        Item* temp = tail_;
        tail_ = tail_->prev;
        tail_->next = nullptr;
        delete temp;
        size_--;
        if(tail_== nullptr){
            return;
        }
        else if(tail_ == head_){
            tail_->first = head_->first;
            tail_->last = head_->last;
        }
        else {
            tail_->first = 0;
            tail_->last = 10;
        }
    }
    else{
        tail_->val[tail_->last - 1].erase();
        tail_->last--;
    }
}
void ULListStr::pop_front(){
    if(head_->first == 9 && head_->last == 10){
        head_->val[9].erase();
        head_->first++;
        Item* temp = head_;
        head_ = head_->next;
        head_->prev = nullptr;
        delete temp;
        size_--;
        if(head_ == nullptr){
            return;
        }
        else if(head_ == tail_){
            head_->first = tail_->first;
            head_->last = tail_->last;
        }
        else {
            head_->first = 0;
            head_->last = 10;
        }
    }
    else{
        head_->val[head_->first].erase();
        head_->first++;
    }

}
std::string const & ULListStr::back() const{
    std::string& back = tail_->val[tail_->last - 1];
    return back;

}
std::string const & ULListStr::front() const{
    std::string& front = head_->val[head_->first];
    return front;
}
std::string* ULListStr::getValAtLoc(size_t loc) const{
    size_t currLoc = 0;
    std::string* toReturn;
    if(head_->last > loc){
        toReturn = &head_->val[head_->first + loc];
        return toReturn;
    }
    else {
        Item* on = head_->next;
        currLoc += head_->last - head_->first;
        while (true) {
            if(on == tail_){
                if(loc > currLoc + tail_->last - tail_->first){
                   return nullptr;
                }
                else{
                    toReturn = &tail_->val[loc - currLoc];
                    return toReturn;
                }
            }
            else{
                if(loc < currLoc + 10 && loc > currLoc){
                    toReturn = &on->val[loc - currLoc];
                    return toReturn;
                }
                else{
                    currLoc += 10;
                    on = on->next;
                }
            }
        }
    }

}
// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
    std::string* ptr = getValAtLoc(loc);
    if(ptr == NULL){
        throw std::invalid_argument("Bad location");
    }
    *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
    std::string* ptr = getValAtLoc(loc);
    if(ptr == NULL){
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
    std::string* ptr = getValAtLoc(loc);
    if(ptr == NULL){
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

void ULListStr::clear()
{
    while(head_ != NULL){
        Item *temp = head_->next;
        delete head_;
        head_ = temp;
    }
    tail_ = NULL;
    size_ = 0;
}

void ULListStr::display() {
    Item* curr = head_;
    while(curr != nullptr){
        for(auto & i : curr->val){
            std::cout << i << " ";
        }
        std::cout << std::endl;
        curr = curr->next;
    }
}

