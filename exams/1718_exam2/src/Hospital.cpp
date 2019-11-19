/*
 * Hospital.cpp
 */

#include "Hospital.h"
//
#include <algorithm>


Hospital::Hospital(unsigned trayC) : trayCapacity(trayC) {}

void Hospital::addDoctor(const Doctor &d1) {
	doctors.push_back(d1);
}

list<Doctor> Hospital::getDoctors() const {
	return doctors;
}

void Hospital::addTrays(stack<Patient> tray1) {
	letterTray.push_back(tray1);
}

list<stack<Patient> > Hospital::getTrays() const {
	return letterTray;
}


unsigned Hospital::numPatients(string medicalSpecialty) const {
	unsigned count = 0;

	for (const Doctor &doctor : doctors)
		if (doctor.getMedicalSpecialty() == medicalSpecialty)
			count += doctor.getPatients().size();

	return count;
}

void Hospital::sortDoctors() {
	vector<Doctor> aux_vector;

	for (const Doctor &doctor : doctors)
		aux_vector.push_back(doctor);

	sort(aux_vector.begin(), aux_vector.end(), [](const Doctor &a, const Doctor &b) {

		// sorts by patients list size.
		if (a.getPatients().size() < b.getPatients().size())
			return true;
		if (b.getPatients().size() < a.getPatients().size())
			return false;

		// sorts by medical speciality.
		if (a.getMedicalSpecialty() < b.getMedicalSpecialty())
			return true;
		if (b.getMedicalSpecialty() < a.getMedicalSpecialty())
			return false;

		// sorts by code.
		return a.getCode() < b.getCode();
	});

	this->doctors.clear();
	for (const Doctor &doc : aux_vector)
		doctors.push_back(doc);
}

bool Hospital::addDoctor(unsigned codM1, string medicalSpecialty1) {
	if (this->getDoctors(medicalSpecialty1) > MAX_DOCS_SPECIALITY)
		return false;

	Doctor doctor(codM1, medicalSpecialty1);
	doctors.push_back(doctor);
	return true;
}


queue<Patient> Hospital::removeDoctor(unsigned codM1) {
	queue<Patient> res;

	for (auto it = doctors.begin(); it != doctors.end(); ++it) {
		if ((*it).getCode() == codM1) {
			res = (*it).getPatients();
			doctors.erase(it);
			return res;
		}
	}

	throw DoctorInexistent();
}


bool Hospital::putInLessBusyDoctor(unsigned cod1, string medicalSpecialty1) {
	int less_patients = -1;
	Doctor *less_busy = nullptr;

	for (Doctor &doctor : doctors) {
		if (doctor.getMedicalSpecialty() == medicalSpecialty1) {
			if (doctor.getPatients().size() < less_patients || less_patients == -1) {
				less_busy = &doctor;
				less_patients = less_busy->getPatients().size();
			}
		}
	}

	if (less_patients == -1)
		return false;

	Patient patient(cod1, medicalSpecialty1);
	less_busy->addPatient(patient);
	return true;
}


void Hospital::processPatient(unsigned codM1) {
	Doctor *doc = nullptr;

	for (Doctor &doctor : doctors) {
		if (doctor.getCode() == codM1) {
			doc = &doctor;
			break;
		}
	}

	if (doc == nullptr) return;

	try {
		Patient to_remove = doc->removeNextPatient();

		for (stack<Patient> &stack : this->letterTray) {
			if (stack.size() < this->trayCapacity) {
				stack.push(to_remove);
				return;
			}
		}

		stack<Patient> new_stack;
		new_stack.push(to_remove);
		this->addTrays(new_stack);

	} catch (const Doctor::PatientInexistent &e) {
		return;
	}
}


unsigned Hospital::removePatients(unsigned codP1) {
	unsigned count = 0;

	for (auto it = letterTray.begin(); it != letterTray.end(); ++it) {
		if ((*it).top().getCode() == codP1) {
			count++;

			(*it).pop();
			if ((*it).empty())
				it = letterTray.erase(it);
		}
	}

	return count;
}

unsigned Hospital::getDoctors(string medicalSpeciality) {
	unsigned count = 0;

	for (const Doctor &doc : doctors)
		if (doc.getMedicalSpecialty() == medicalSpeciality)
			count++;

	return count;
}



