#!/usr/bin/env python3

from PIL import Image, ImageOps
import argparse

def setup_cli_args():
    parser = argparse.ArgumentParser(description="Converts BMP to XBM")

    parser.add_argument("source",
                        type=str,
                        default='image.bmp',
                        help="Source image")

    parser.add_argument("destination",
                        type=str,
                        default='image.xbm',
                        help="Destination image")

    return parser

def run():
    parser = setup_cli_args()
    args = parser.parse_args()

    img = Image.open(args.source)

    # rgb_list = list(img.getdata())

    # Export to X11 bitmap
    ImageOps.invert(img).convert('1').save(args.destination)


if __name__ == '__main__':
    run()