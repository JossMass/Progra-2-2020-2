#include <conio.h>
#include <ctime>

#include "ZoneLeader.h"

int main() {
	srand(time(NULL));

	Person* client1 = new Person("Danny", "Ramirez", 12568921, "La Molina");
	Person* client2 = new Person("Yara", "Gonzales", 23313531, "Miraflores");
	Person* client3 = new Person("Fredy", "Silvestre", 31321651, "San Isidro");

	Seller* seller = new Seller("Marco", "Torres", 12314324, "San Borja", 3229932, 2000);
	seller->addClient(client1);
	seller->addClient(client2);
	seller->addClient(client3);

	Secretary* secretary = new Secretary("Franchesca", "Navarrete", 21231312, "San Miguel", 934394383, 3000);

	ZoneLeader* zoneLeader = new ZoneLeader("Jose", "Mascaro", 341412321, "Chorrillos", 394393499, 5000, secretary);
	zoneLeader->addSeller(seller);

	//zoneLeader->increaseSalary();
	//seller->increaseSalary();
	//secretary->increaseSalary();

	//zoneLeader->getZoneLeaderInfo();
	//seller->getSellerInfo();
	//secretary->getSecretaryInfo();

	secretary->getSupervisorInfo();

	_getch();
	return 0;
}