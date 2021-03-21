#pragma once
// code for workersa and to decide if there are workers available
class Worker {
private:
	bool isAvail;
public:
	Worker() { isAvail = true; }

	bool assign() {
		if (!isAvail)return false;

		isAvail = false;
		return true;
	}

	bool isAvailable() { return isAvail; }
};
