#include <vector>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

static int subCount = 1;

class ISubscriber {
public:
	virtual ~ISubscriber() {};
	virtual void Update(const string& message_data) = 0;
};


class IPublisher {
public:
	virtual ~IPublisher() {};
	virtual void Subscribe(ISubscriber* sub) = 0;
	virtual void Unsubscribe(ISubscriber* sub) = 0;
	virtual void Notify() = 0;
};

class Publisher : public IPublisher {
private:
	list<ISubscriber*> subs_;
	string message_;

	void Notify() {
		for (auto sub : subs_) {
			sub->Update(message_);
		}
	}
public:
	virtual ~Publisher() {
		cout << __LINE__ << ": Publisher destroy" << endl;
	}

	void CreateMessage(string message = "Empty") {
		message_ = message;
		Notify();
	}

	virtual void Subscribe(ISubscriber* sub) {
		subs_.push_back(sub);
	}

	virtual void Unsubscribe(ISubscriber* sub) {
		auto subItr = find(subs_.begin(), subs_.end(), sub);
		if (subItr != subs_.end()) {
			subs_.erase(subItr);
		}
	}


};



class Subscriber : public ISubscriber {
public:
	Subscriber(IPublisher& pub) : pubRef(pub){
		pubRef.Subscribe(this);
		count_ = subCount++;
		cout << "Created Sub: " << count_ << endl;
	}

	virtual ~Subscriber() {
		cout << "Destroy sub: " << count_ << endl;
		subCount--;
	}
	
	virtual void Update(const string& message_data) {
		data_ = message_data;
		PrintData();
	}

private:
	string data_;
	IPublisher& pubRef;
	void PrintData() {
		cout << "Sub: " << count_ << " New data : " << data_ << endl;
	}
	int count_;
};

class ObserverClient {
public:
	ObserverClient() {
		Publisher p1;
		Subscriber s1(p1);
		Subscriber s2(p1);

		p1.CreateMessage("Message1");
		p1.CreateMessage("Message2");
	}


};
