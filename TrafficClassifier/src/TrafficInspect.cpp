#include <iostream>
#include "Database.h"
#include "Classificator.h"
using namespace std;

int main() {

		//colocate database in memory
		Database * database= new Database("/media/Iomega_HDD/results/",100);
		database->carrega();
		//database->view_Signature();
		//getchar();


			vector<string> file_names;
			vector<string> tamanho;
			std::stringstream ss;
			std::string path;

			/*	path ="/media/Iomega_HDD/Traces_VoIP_2010/labredes17012011/";
				file_names.push_back(path +"skype_G729_TCP_17012011_1.pcap");
				file_names.push_back(path +"skype_G729_UDP_17012011_1.pcap");
				file_names.push_back(path +"skype_NWC_TCP_17012011_1.pcap");
				file_names.push_back(path +"skype_NWC_UDP_17012011_1.pcap");
				file_names.push_back(path +"skype_PCMA_TCP_17012011_1.pcap");
				file_names.push_back(path +"skype_PCMA_UDP_17012011_1.pcap");
				file_names.push_back(path +"skype_PCMU_TCP_17012011_1.pcap");
				file_names.push_back(path +"skype_PCMU_UDP_17012011_1.pcap");
				file_names.push_back(path +"skype_SILK_MB_V3_TCP_17012011_1.pcap");
				file_names.push_back(path +"skype_SILK_MB_V3_UDP_17012011_1.pcap");
				file_names.push_back(path +"skype_SILK_NB_V3_TCP_17012011_1.pcap");
				file_names.push_back(path +"skype_SILK_NB_V3_UDP_17012011_1.pcap");
				file_names.push_back(path +"skype_SILK_TCP_17012011_1.pcap");
				file_names.push_back(path +"skype_SILK_UDP_17012011_1.pcap");
				file_names.push_back(path +"skype_SILK_V3_TCP_17012011_1.pcap");
				file_names.push_back(path +"skype_SILK_V3_UDP_17012011_1.pcap");
				file_names.push_back(path +"skype_SILK_WB_TCP_17012011_1.pcap");
				file_names.push_back(path +"skype_SILK_WB_UDP_17012011_1.pcap");
				file_names.push_back(path +"skype_SILK_WB_V3_TCP_17012011_1.pcap");
				file_names.push_back(path +"skype_SILK_WB_V3_UDP_17012011_1.pcap");
				file_names.push_back(path +"skype_SVOPC_SB_TCP_17012011_1.pcap");
				file_names.push_back(path +"skype_SVOPC_SB_UDP_17012011_1.pcap");
				file_names.push_back(path +"skype_SVOPC_SB_UDP_17012011_2.pcap");
				file_names.push_back(path +"skype_SVOPC_TCP_17012011_1.pcap");
				file_names.push_back(path +"skype_SVOPC_UDP_17012011_1.pcap");*/

			path = "/media/Iomega_HDD/Traces/Traces_Joao_S/";
					file_names.push_back(path +"audio_streaming_on_demand_Flash_24082010_1_CLEAN.pcap");
			//path= "/media/Iomega_HDD/Traces_VoIP_2010/labredes19012011/";

				//file_names.push_back(path +"skype_A_G729_UDP_19012011_1.pcap");
				//file_names.push_back(path +"skype_A_PCMA_UDP_19012011_1.pcap");
				//file_names.push_back(path +"skype_A_PCMU_UDP_19012011_1.pcap");
				//file_names.push_back(path +"skype_A_SILK_MB_V3_UDP_19012011_1.pcap");
				//file_names.push_back(path +"skype_A_SILK_NB_V3_UDP_19012011_1.pcap");
				//file_names.push_back(path +"skype_A_SILK_WB_V3_UDP_19012011_1.pcap");
				//file_names.push_back(path +"skype_EG711A_TCP_19012011_1.pcap");
				//file_names.push_back(path +"skype_EG711A_UDP_19012011_1.pcap");
				//file_names.push_back(path +"skype_EG711U_TCP_19012011_1.pcap");
				//file_names.push_back(path +"skype_EG711U_UDP_19012011_1.pcap");
				//file_names.push_back(path +"skype_G729_TCP_19012011_1.pcap");
				//file_names.push_back(path +"skype_G729_UDP_19012011_1.pcap");
				//file_names.push_back(path +"skype_ILBC_TCP_19012011_1.pcap");
				//file_names.push_back(path +"skype_ILBC_UDP_19012011_1.pcap");
				//file_names.push_back(path +"skype_IPCMWB_TCP_19012011_1.pcap");
				//file_names.push_back(path +"skype_IPCMWB_UDP_19012011_1.pcap");
				//file_names.push_back(path +"skype_ISAC_TCP_19012011_1.pcap");
				//file_names.push_back(path +"skype_ISAC_UDP_19012011_1.pcap");
				//file_names.push_back(path +"skype_PCMA_TCP_19012011_1.pcap");
				//file_names.push_back(path +"skype_PCMA_UDP_19012011_1.pcap");
				//file_names.push_back(path +"skype_PCMU_TCP_19012011_1.pcap");
				//file_names.push_back(path +"skype_PCMU_UDP_19012011_1.pcap");

				//path= "/home/miguel/";

					//file_names.push_back(path +".pcap");


				/*path= "/media/Iomega_HDD/Traces_VoIP_2010/labredes21012011/";
				file_names.push_back(path +"sip_B-AL_SPEEX16_UDP_21012011_1.pcap");
				file_names.push_back(path +"sip_B-AL_SPEEX8_UDP_21012011_1.pcap");
				file_names.push_back(path +"sip_B-L_GSM_UDP_21012011_1.pcap");
				file_names.push_back(path +"sip_B-L_PCMU_UDP_21012011_1.pcap");
				file_names.push_back(path +"sip_B-L_SPEEX16_UDP_21012011_1.pcap");
				file_names.push_back(path +"sip_B-L_SPEEX32_UDP_21012011_1.pcap");
				file_names.push_back(path +"sip_B-L_SPEEX8_UDP_21012011_1.pcap");
				file_names.push_back(path +"sip_L-AL_GSM_UDP_21012011_1.pcap");
				file_names.push_back(path +"sip_L-AL_PCMA_UDP_21012011_1.pcap");
				file_names.push_back(path +"sip_L-L_GSM_UDP_21012011_1.pcap");
				file_names.push_back(path +"sip_L-L_PCMA_UDP_21012011_1.pcap");
				file_names.push_back(path +"sip_L-L_PCMU_UDP_21012011_1.pcap");
				file_names.push_back(path +"sip_L-L_SPEEX16_UDP_21012011_1.pcap");
				file_names.push_back(path +"sip_L-L_SPEEX32_UDP_21012011_1.pcap");
				file_names.push_back(path +"sip_L-L_SPEEX8_UDP_21012011_1.pcap");*/

				for (int i = 0; i != file_names.size(); i++)
						{
							Classificator c(1515,100,500);



							PacketSource PS;

							PS.OpenOfflineSource(file_names[i].c_str());

						    bool end = false;

						    while(!end)
						        try
						        {
						           Packet *Pckt;


						           Pckt = PS.NextPacket();
						           int len = Pckt->Len();
						           c.distribuicao(len,database);
						          // c.view_CHI_2_RESULTS(database);
						    	   delete Pckt;
								}
								catch (No_More_Packets e1)
								{
									end = true;
								}
								catch (Timeout_Expired e2)
								{
									cout << "Timeout: " << e2.what() << "\n";
									end = true;
								}
								catch (Packet_Reading_Error e3)
								{
									cout << "Failed: " << e3.what() << "\n";
									end = true;
								}
							PS.CloseSource();

							//c.dt();
							c.view_CHI_2_RESULTS(database);

						//	std::cout <<"Final:" <<c.getClasse() << " " << c.getSoma() << std::endl;

						}


	return 0;
}
