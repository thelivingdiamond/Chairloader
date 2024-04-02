# Simulates GitHub API for updates.
import argparse
import http.server
import json
import socketserver

IP = '127.0.0.1'

parser = argparse.ArgumentParser()
parser.add_argument('--port', type=int, default=8080)
parser.add_argument('--version')
args = parser.parse_args()


class HTTPRequestHandler(http.server.SimpleHTTPRequestHandler):
    def do_GET(self) -> None:
        if self.path.startswith('/releases'):
            super().do_GET()
        elif self.path.startswith('/repos/thelivingdiamond/Chairloader/releases/latest'):
            self.handle_latest()
        else:
            self.send_error(http.HTTPStatus.NOT_FOUND, 'File not found')

    def handle_latest(self):
        obj_response = {
            'tag_name': str(args.version),
            'assets': [
                {
                    'browser_download_url': f'http://{IP}:{args.port}/releases/latest.zip',
                }
            ]
        }

        json_response = json.dumps(obj_response)
        self.send_response(http.HTTPStatus.OK)
        self.send_header("Content-type", 'application/json')
        self.send_header("Content-Length", str(len(json_response)))
        self.end_headers()
        self.wfile.write(json_response.encode('UTF-8'))
        self.wfile.flush()


handler = HTTPRequestHandler

with socketserver.TCPServer((IP, args.port), handler) as httpd:
    print("serving at port", args.port)
    httpd.serve_forever()
