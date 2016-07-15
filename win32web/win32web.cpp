// 
//

#include "stdafx.h"
#include <curl/curl.h>


int main(int argc, char** argv)
{
	CURL *curl;
	CURLcode res;


	// example connect over 2 post-messages
	static const char *web1 = "http://ogledb.astrouw.edu.pl/~ogle/photdb/query.php?qtype=phot&first=1";
	static const char *post1 = "db_target=bulge&dbtyp=psf2&sort=field&val_field=&val_starid=&disp_x=on&valmin_x=&valmax_x=&disp_y=on&valmin_y=&valmax_y=&disp_starcat=on&val_starcat=&disp_ra=on&valmin_ra=&valmax_ra=&disp_decl=on&valmin_decl=&valmax_decl=&disp_ngood=on&valmin_ngood=&valmax_ngood=&disp_pgood=on&valmin_pgood=&valmax_pgood=&disp_imean=on&valmin_imean=&valmax_imean=&disp_imed=on&valmin_imed=&valmax_imed=&disp_isig=on&valmin_isig=&valmax_isig=&disp_imederr=on&valmin_imederr=&valmax_imederr=&disp_ndetect=on&valmin_ndetect=&valmax_ndetect=&use_query=on&query=RA%3Eh2d%28%2718%3A01%3A00%27%29+and+RA%3Ch2d%28%2718%3A01%3A30%27%29+and+Isig%3C0.01&sorting=ASC&pagelen=50&maxobj=";

	static const char *web2 = "http://ogledb.astrouw.edu.pl/~ogle/photdb/senddata.php";
	static const char *post2 = "tmpdir=1468480934.00928j&sqlquery=SELECT+Field%2CStarID%2CX%2CY%2CStarCat%2CRA%2CDecl%2CNgood%2CPgood%2CI%2CIsig%2CImed%2CImederr+FROM+bul2+WHERE+&sqlquery_p=SELECT+FROM+bul2+WHERE+RA%3Eh2d%28%2718%3A01%3A00%27%29+and+RA%3Ch2d%28%2718%3A01%3A30%27%29+and+Isig%3C0.01&sqldb=bul2&database=phot&fname=query.tar.gz&nrows=439563&limit=&rem_ip=85.176.37.35&data=table&points=good&db=DIA";


	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, web1);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post1);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(post1));
		res = curl_easy_perform(curl);
		if (res != CURLE_OK) {
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
			return E_FAIL;
		}

		curl_easy_setopt(curl, CURLOPT_URL, web2);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post2);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(post2));
		res = curl_easy_perform(curl);
		if (res != CURLE_OK) {
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
			return E_FAIL;
		}

		curl_easy_cleanup(curl);
	}

    return 0;
}

