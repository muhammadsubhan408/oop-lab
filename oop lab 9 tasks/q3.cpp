#include<iostream>
#include<string>
using namespace std;

class Doctor;
class Billing;

class PatientRecord{
    string name;
    string patientID;
    string dateOfBirth;
    string medicalHistory;
    string currentDiagnosis;
    string billingDetails;

public:
    PatientRecord(string n, string id, string dob)
        : name(n), patientID(id), dateOfBirth(dob), medicalHistory(""), currentDiagnosis(""), billingDetails("") {}

    string getPublicData() const{
        return "Name: " + name + "\nID: " + patientID + "\nDate of Birth: " + dateOfBirth;
    }

    string getMedicalData(const Doctor& requester) const;
    void updateMedicalHistory(const Doctor& requester, const string& history);
    void updateDiagnosis(const Doctor& requester, const string& diagnosis);
    void addBillingDetails(const Billing& requester, const string& bill);
    string getBillingInfo(const Billing& requester) const;
    friend class Doctor;
    friend class Billing;
};

class Doctor{
public:
    void viewMedicalRecord(const PatientRecord& record) const{
        cout << "Doctor viewing medical data:\n" << record.getMedicalData(*this) << "\n";
    }

    void updateMedicalRecord(PatientRecord& record, const string& history, const string& diagnosis) const{
        record.updateMedicalHistory(*this, history);
        record.updateDiagnosis(*this, diagnosis);
    }
};

class Billing{
public:
    void addCharge(PatientRecord& record, const string& charge) const{
        record.addBillingDetails(*this, charge);
    }

    void viewBillingInfo(const PatientRecord& record) const{
        cout << "Billing viewing billing data:\n" << record.getBillingInfo(*this) << "\n";
    }
};

class Receptionist{
public:
    void viewPatientBasicInfo(const PatientRecord& record) const{
        cout << "Receptionist viewing public data:\n" << record.getPublicData() << "\n";
    }
};

	string PatientRecord::getMedicalData(const Doctor& requester) const{
    	return "History: " + medicalHistory + "\nDiagnosis: " + currentDiagnosis;
	}

	void PatientRecord::updateMedicalHistory(const Doctor& requester, const string& history){
    	medicalHistory = history;
	}

	void PatientRecord::updateDiagnosis(const Doctor& requester, const string& diagnosis){
    	currentDiagnosis = diagnosis;
	}

	void PatientRecord::addBillingDetails(const Billing& requester, const string& bill){
    	billingDetails += (billingDetails.empty() ? "" : "\n") + bill;
	}

	string PatientRecord::getBillingInfo(const Billing& requester) const{
    	return billingDetails.empty() ? "No billing info." : billingDetails;
	}

int main(){
    PatientRecord patient("Alice Smith", "P12345", "1990-08-22");
    Doctor doc;
    Billing bill;
    Receptionist rec;

    cout << "\n-- Receptionist tries to access data --\n";
    rec.viewPatientBasicInfo(patient);

    cout << "\n-- Doctor updates and views medical record --\n";
    doc.updateMedicalRecord(patient, "No prior allergies", "Flu and fever");
    doc.viewMedicalRecord(patient);

    cout << "\n-- Billing adds and views billing info --\n";
    bill.addCharge(patient, "Consultation - $100");
    bill.viewBillingInfo(patient);

    return 0;
}

