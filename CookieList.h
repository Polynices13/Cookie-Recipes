
#ifndef COOKIELIST_H
#define COOKIELIST_H

#include "Cookie.h"

class Node
{
public:
	Node() : cookie(), next(nullptr) {}
	Node(const Cookie& newCookie, Node* newNext)
		: cookie(newCookie), next(newNext) {}
	Cookie& getCookie() { return cookie; } 
	Node* getNext() const { return next; }
	void setCookie(const Cookie& newCookie) { cookie = newCookie; }
	void setNext(Node* newNext) { next = newNext; }
	~Node() {}
private:
	Cookie cookie;
	Node* next;
};

class CookieList
{
public:
	// Constructors
	CookieList();
	
	// Function addCookie
	void addCookie(const Cookie& aCookie);
	void addCookie(const std::string& newName, size_t newCalories,
		const std::set<std::string>& newIngredients, size_t newServings);

	// Accessor function
	size_t getCount() const;

	// Boolean functions
	bool isEmpty() const;
	bool searchCookie(const std::string& aCookie) const;

	// Print functions
	void printAllCookies() const;

	// Function clearList
	void clearList();

	// The Big Three
	CookieList(const CookieList& otherCookieList);
	CookieList& operator=(const CookieList& otherCookieList);		
	~CookieList();
	
	//Added functions
    void printCookiesSelection() const;
    void printRecipe(size_t cookieSelection) const;
	void printLimitedCalories(size_t calories);
	void printCalories(size_t cookieSelection) const;
    
private:
	// Helper functions for copy assignment operator
	void copyCallingObjIsEmpty(const CookieList& otherCookieList);
	void copyObjectsSameLength(const CookieList& otherCookieList);
	void copyCallingObjLonger(const CookieList& otherCookieList);
	void copyCallingObjShorter(const CookieList& otherCookieList);
    
    //Added function
    Node* getCookieLocation(size_t cookieSelection) const;
    
	Node* first;
	Node* last;
	size_t count;
};

#endif
