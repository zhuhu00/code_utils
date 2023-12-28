import argparse
import time
from pathlib import Path
import requests
from tqdm import tqdm
import zipfile
from http.client import IncompleteRead, HTTPException
from joblib import Parallel, delayed, parallel_backend


# update accordingly
headers = {
  'authority': 'cuhko365-my.sharepoint.com',
  'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7',
  'accept-language': 'en-US,en;q=0.9,zh-CN;q=0.8,zh;q=0.7',
  'cookie': 'FedAuth=77u/PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0idXRmLTgiPz48U1A+VjEzLDBoLmZ8bWVtYmVyc2hpcHx1cm4lM2FzcG8lM2Fhbm9uIzMyYTAzM2NhZjk3OGM5NzRiZDNkZTA1YTA0YTEwNDdmN2I4NWI1MDMxYzEwZjNiMmM5ODE5MGMxZDhhY2JlZjYsMCMuZnxtZW1iZXJzaGlwfHVybiUzYXNwbyUzYWFub24jMzJhMDMzY2FmOTc4Yzk3NGJkM2RlMDVhMDRhMTA0N2Y3Yjg1YjUwMzFjMTBmM2IyYzk4MTkwYzFkOGFjYmVmNiwxMzM0ODE0NjAwNDAwMDAwMDAsMCwxMzM0ODIzMjEwNDM1NTE0NjMsMC4wLjAuMCwyNTgsZTU4OThiN2EtOWM4Ny00YTRiLWIyMmEtMmRmM2YzNTVlMDFlLCwsMjFjZmZiYTAtNjBkMC0yMDAwLWM4NGQtMTI3Y2QzYTMzOTE3LDIxY2ZmYmEwLTYwZDAtMjAwMC1jODRkLTEyN2NkM2EzMzkxNyxqcXI2VTluUk1VK0c1MVdia3pJVm93LDAsMCwwLCwsLDI2NTA0Njc3NDM5OTk5OTk5OTksMCwsLCwsLCwwLCwxOTU4NjMsR0FkeFdYM3FnLXBsUDRlOVhCUDF5MTZpZmpVLGtKMm42ZE5aOU12bWs0NVE4UFlPemxadW9GTnJueFNuWHo4U1RyZjRQZERTSG9OdVE2N1BIemZGZ25rQTlPcExpWlg2Mk9UZ2RuQ3JGdzFMblhnRTJ0WkVpZkNlV0RnbFIzbW9MRkVKREliamlmOTNYeUhHNVEvY2ptVVZnb0h5bEVqVW1LcEZlcmdXcHkvSjNDOEgxdlJyOEEzeVhFS05BT011MkxQZDh1SWZJRHZWQXJoMWdjeG9jU3J6QVE2Ti9EVTdodjBrYTRwZDZJakU0TmYyTnJObFRRWXlWMFhBTDFmSWNTSEJoeElHbTI0cmxWeG93bERDVFNzRlphT3NTLzBOcFJ0NlZ3aGduMEw1ODVuUmNSYUtXR2xiQlhMQjQxeTlIWWcxMEE4eTBCZDBETmNmZEo5TENjbzQ4d2lPTlZTVzY3ZXNEcmxicGpEcGpyMk5uQT09PC9TUD4=',
  'referer': 'https://cuhko365-my.sharepoint.com/personal/gaplab_cuhk_edu_cn/_layouts/15/onedrive.aspx?ga=1&id=%2Fpersonal%2Fgaplab%5Fcuhk%5Fedu%5Fcn%2FDocuments%2FMVImgNet%5FRelease',
  'sec-ch-ua': '"Not A(Brand";v="99", "Microsoft Edge";v="121",',
  'sec-ch-ua-mobile': '',
  'sec-ch-ua-platform': '',
  'sec-fetch-dest': '',
  'sec-fetch-mode': '',
  'sec-fetch-site': '',
  'sec-fetch-user': '',
  'service-worker-navigation-preload': '',
  'upgrade-insecure-requests': '',
  'user-agent': '',
}

def check_file_exists(output_file):
    if not output_file.exists():
        return False
    else:
        try:
            with zipfile.ZipFile(output_file, 'r') as zip_file:
                zip_file.printdir()
                return True
        except zipfile.BadZipFile:
            print(f'Bad zip file: {output_file}')
            return False

def download_with_retry(url, headers, output_file, max_retries=3, timeout=10):
    for attempt in range(1, max_retries + 1):
        try:
            with requests.get(url, headers=headers, stream=True, timeout=timeout) as response:
                response.raise_for_status()
                total_size = int(response.headers.get('Content-Length', 0))
                with tqdm(total=total_size, unit='B', unit_scale=True, unit_divisor=1024,
                        desc=output_file.stem.split('.')[0]) as pbar:
                    with open(output_file, 'wb') as f:
                        for chunk in response.iter_content(chunk_size=8 * 1024):
                            if chunk:
                                f.write(chunk)
                                pbar.update(len(chunk))
            break
        # except (requests.exceptions.RequestException, requests.exceptions.ChunkedEncodingError, \
        #         IncompleteRead, HTTPException, requests.Timeout):
        except:
            if attempt < max_retries:
                print(f"Attempt {attempt} failed. Retrying in 5 seconds...")
                time.sleep(5)
            else:
                print(f"Failed after {max_retries} attempts.")
                raise

def download_file_with_progress(url, headers, output_file, timeout=10):
    for _ in range(timeout):
        if check_file_exists(output_file):
            break
        else:
            download_with_retry(url, headers, output_file, max_retries=5)

def main(args):
    filepath = 'links.txt'
    data_root = Path('./')
    with open(filepath, 'r') as file:
        lines = file.readlines()
    urls = [line.strip() for line in lines]

    #with parallel_backend('multiprocessing', n_jobs=5):
    #    (Parallel()(delayed(download_file_with_progress)(url, headers, data_root / f'mvi_{i:02d}.zip')
    #                     for i, url in enumerate(urls)))
    for i in range(args.begin_idx, args.end_idx + 1):
        url = urls[i]
        tgt_path = data_root / f'mvi_{i:02d}.zip'
        print(tgt_path)
        download_file_with_progress(url, headers, tgt_path)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--begin_idx", type=int, default=0)
    parser.add_argument("--end_idx", type=int, default=42)
    args = parser.parse_args()
    main(args)